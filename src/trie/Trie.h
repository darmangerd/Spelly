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
    TrieNode<Word *> *root_;
    string alphabet_;

    void recursiveAutocomplete(TrieNode<Word *> *currentWord, Word **suggestions, unsigned int &wordCount,
                               unsigned int maxWords,
                               unsigned int &depth, unsigned int maxDepth) const;

public:
    explicit Trie(string alphabet, const vector<Word *> &words);

    ~Trie();

    /**
     * Insert a word into the Trie data structure
     * @param word The word to insert
     */
    void insert(const Word &word) const;

    /**
     * Search for a word inside the Trie data structure
     * @param word
     * @return The word pointer if found, otherwise nullptr
     */
    [[nodiscard]] Word *search(const string &word) const;

    /**
     * Find the best accurate word that begins with the partial word in the Trie data structure
     * @param word The partial word to look for
     * @param maxWords The maximum number of words to find
     * @param maxDepth The max depth (it limits the complexity)
     * @return An array of word pointers with the length of <maxWords>
     */
    [[nodiscard]] Word **autocomplete(const string &word, unsigned int maxWords = 3, unsigned int maxDepth = 10) const;

    friend ostream &operator<<(ostream &os, const Trie &t);
};
