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

    /**
     * Find all the accurate candidates for a misspelled word
     * @param word The misspelled word
     * @return A vector of words pointer and a their Levenshtein distance
     */
    [[nodiscard]] vector<pair<Word *, unsigned int>> findCandidates(Word &word);

    /**
     * Find all the accurate candidates for a misspelled word
     * @param word The misspelled word
     * @return A vector of words pointer and a their Levenshtein distance
     */
    [[nodiscard]] vector<pair<Word *, unsigned int>> findCandidates(const string &word);
};
