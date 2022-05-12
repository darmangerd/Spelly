//
// Created by owen on 09.05.22.
//

#pragma once

#include <iostream>
#include "Word.h"
#include "TrieNode.h"
#include <vector>



class Trie {
public:
    TrieNode *root;
    Trie();
    ~Trie();
    bool search(Word word);
    void insert(Word word);
};
