//
// Created by owen on 04.06.22.
//

#pragma one

#include "../word/Word.h"
#include <vector>

class Correction {
private:
    vector<Word *> *wordsChunks;
    unsigned int numberOfThreads;

public:
    explicit Correction(vector<Word *> words, unsigned int numberOfThreads);

    vector<pair<Word *, unsigned int>> findCandidates(const string &word);
};
