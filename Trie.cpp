//
// Created by owen on 09.05.22.
//

#include "Trie.h"
Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(Word word) {
    TrieNode *current = root;
    for (int i = 0; i < word.getSize(); i++) {
        if (current->children[word.getContent()[i]] == nullptr) {
            current->children[word.getContent()[i]] = new TrieNode();
        }
        current = current->children[word.getContent()[i]];
    }
}

bool Trie::search(Word word) {
    TrieNode *current = root;
    for (int i = 0; i < word.getSize(); i++) {
        if (current->children[word.getContent()[i]] == nullptr) {
            return false;
        }
        current = current->children[word.getContent()[i]];
    }
    return true;
}