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
    string* search(Word word, int maxCost);
    void searchRecursive(Word word, int length, TrieNode *current, TrieNode *previous, string *result, int index);
    void insert(Word word);
};
