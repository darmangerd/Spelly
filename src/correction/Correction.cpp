//
// Created by owen on 04.06.22.
//

#include "Correction.h"
#include "../misc/Utils.h"
#include <utility>
#include <thread>

using namespace std;

Correction::Correction(vector<Word *> words, unsigned int numberOfThreads) : numberOfThreads_(numberOfThreads) {
    this->wordsChunks_ = Utils::createChunks(std::move(words), numberOfThreads);
    this->numberOfThreads_ = wordsChunks_.size();
}

vector<pair<Word *, unsigned int>> Correction::findCandidates(Word &wordToFind) {
    unsigned int minDistance = INT32_MAX;
    vector<pair<Word *, unsigned int>> candidates;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

    auto findCandidates = [&](vector<Word *> *words) {
        for (auto word: *words) {
            auto distance = wordToFind.levenshteinDistance(*word);

            if (distance < minDistance) {
                pthread_mutex_lock(&m);
                candidates.clear();
                minDistance = distance;
                candidates.emplace_back(make_pair(word, distance));
                pthread_mutex_unlock(&m);
            } else if (distance == minDistance) {
                pthread_mutex_lock(&m);
                candidates.emplace_back(make_pair(word, distance));
                pthread_mutex_unlock(&m);
            }
        }
    };

    thread threads[this->numberOfThreads_];
    for (unsigned int i = 0; i < numberOfThreads_; i++) {
        threads[i] = thread(findCandidates, &this->wordsChunks_[i]);
    }

    for (unsigned int i = 0; i < numberOfThreads_; i++) {
        threads[i].join();
    }

    return candidates;
}

vector<pair<Word *, unsigned int>> Correction::findCandidates(const string &word) {
    Word wordToFind(word);
    return this->findCandidates(wordToFind);
}
