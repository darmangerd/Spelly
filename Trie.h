//
// Created by owen on 09.05.22.
//

#pragma once

#include <iostream>
#include "Word.h"

class Trie {
public:
    Trie();
    ~Trie();
    bool search(Word word);
    void insert(Word word);
};
