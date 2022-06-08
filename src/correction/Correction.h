//
// Created by owen on 04.06.22.
//

#pragma once

#include "../word/Word.h"
#include <vector>

class Correction {
private:
    vector<vector<Word *>> wordsChunks_;
    unsigned int numberOfThreads_;

public:
    explicit Correction(vector<Word *> words, unsigned int numberOfThreads);

    ~Correction() = default;

    [[nodiscard]] vector<pair<Word *, unsigned int>> findCandidates(Word &word);

    [[nodiscard]] vector<pair<Word *, unsigned int>> findCandidates(const string &word);
};
