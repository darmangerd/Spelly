//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include "Word.h"

class WordList {
public:
    WordList();

    ~WordList();

    void addWord(Word word);

    Word *getWords();

    bool WordExists(Word word);

    Word *getNearestWords(Word word, int maxWords);

    Word *autoComplete(Word partialWord, int maxWords);

private:
    std::string *words;

};
