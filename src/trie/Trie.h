//
// Created by owen on 09.05.22.
//

#pragma once

#include <iostream>
#include "TrieNode.h"
#include <vector>
#include "../misc/Utils.h"
#include "../word/Word.h"

using namespace std;

class Trie {
private:
    TrieNode<Word *> *root;
    string alphabet;

    void recursiveAutocomplete(TrieNode<Word *> *currentWord, Word **suggestions, unsigned int &wordCount,
                               unsigned int maxWords,
                               unsigned int &depth, unsigned int maxDepth) const;

public:
    explicit Trie(string alphabet, const vector<Word *> &words);

    void insert(const Word &word) const;

    Word *search(const string &word) const;

    Word **autocomplete(const string &word, unsigned int maxWords = 3, unsigned int maxDepth = 10) const;

    friend ostream &operator<<(ostream &os, const Trie &t);
};
