//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include <set>
#include "Word.h"

using namespace std;

class WordList {
private:
    set<Word> words;

public:
    WordList();

    ~WordList();

    unsigned long addWord(Word &word);

    const vector<Word> &getWords() const;

    bool WordExists(Word word) const;

    const Word &getNearestWords(Word word, int maxWords) const;

    const Word &autoComplete(Word partialWord, int maxWords) const;
};
