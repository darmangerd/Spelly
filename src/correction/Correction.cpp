//
// Created by owen on 04.06.22.
//

#include "Correction.h"
#include "../misc/Utils.h"
#include <utility>
#include <thread>

using namespace std;

Correction::Correction(vector<Word *> words, unsigned int numberOfThreads) : numberOfThreads(numberOfThreads) {
    this->wordsChunks = Utils::createChunks(words, numberOfThreads);
}

Correction::~Correction() {
    delete[] this->wordsChunks;
}

vector<pair<Word *, unsigned int>> Correction::findCandidates(Word &wordToFind) {
    unsigned int minDistance = INT32_MAX;
    vector<pair<Word *, unsigned int>> candidates;
    mutex m;

    auto findCandidates = [&](vector<Word *> *words) {
        for (auto word: *words) {
            auto distance = wordToFind.levenshteinDistance(*word);

            if (distance < minDistance) {
                m.lock();
                candidates.clear();
                minDistance = distance;
                candidates.emplace_back(make_pair(word, distance));
                m.unlock();
            } else if (distance == minDistance) {
                m.lock();
                candidates.emplace_back(make_pair(word, distance));
                m.unlock();
            }
        }
    };

    thread threads[this->numberOfThreads];
    for (unsigned int i = 0; i < numberOfThreads; i++) {
        threads[i] = thread(findCandidates, &this->wordsChunks[i]);
    }

    for (unsigned int i = 0; i < numberOfThreads; i++) {
        threads[i].join();
    }

    return candidates;
}

vector<pair<Word *, unsigned int>> Correction::findCandidates(const string &word) {
    Word wordToFind(word);
    return this->findCandidates(wordToFind);
}
