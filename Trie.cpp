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

string* Trie::search(Word word, int length) {
    TrieNode *current = root;
    string *result = new string[length];
    for (int i = 0; i < word.getSize(); i++) {
        current = current->children[word.getContent()[i]];
    }
    searchRecursive(word, length, current, root, result, 0);
}
void Trie::searchRecursive(Word word, int length, TrieNode *current, TrieNode *previous, string *result, int index) {
    if (index == 0) {
        current = current->children[word.getContent()[index]];
        searchRecursive(word, length, current, previous, result, index + 1);
    }
    else {
        if(index < length){
            previous = current;
            current = current->children[word.getContent()[index]];
            searchRecursive(word, length, current, previous, result, index + 1);
        }
    }
    if (current->isWord) {
        result[length] = word.getContent();
    }
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != nullptr) {
            Word newWord = word;
            newWord.addLetter(i);
            searchRecursive(newWord, length + 1, current->children[i], result);
        }
    }
}

