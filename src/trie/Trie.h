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

    Word *recursiveAutocomplete(TrieNode<Word *> *currentWord) const;

public:
    explicit Trie(const string &path);

    void insert(const Word &word) const;

    Word *search(const string &word) const;

    Word **autocomplete(const string &word, unsigned int maxWords = 3) const;

    friend ostream &operator<<(ostream &os, const Trie &t);
};
