//
// Created by owen on 09.05.22.
//

#pragma once

#include <iostream>
#include "Word.h"
#include "TrieNode.h"
#include <vector>
#include "Utils.h"


class Trie {
public:
    TrieNode<Word *> *root;

    explicit Trie(const string &path);

    void insert(const Word &word) const;

    Word *search(const string &word) const;

    friend ostream &operator<<(ostream &os, const Trie &t);
};
