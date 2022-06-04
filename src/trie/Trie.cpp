//
// Created by owen on 09.05.22.
//

#include <utility>
#include "Trie.h"

Trie::Trie(string alphabet, const vector<Word *> &words) : alphabet(std::move(alphabet)) {
    this->root = new TrieNode<Word *>(nullptr, false, this->alphabet.length());

    for (auto word: words) {
        this->insert(*word);
    }
}

void Trie::insert(const Word &word) const {
    auto current = this->root;

    for (unsigned int i = 0; i < word.length(); i++) {
        int indexInAlphabet = Utils::getIndexInAlphabet(word.getText()[i], this->alphabet);

        if (indexInAlphabet < 0) continue;

        if (current->children[indexInAlphabet] == nullptr) {
            current->children[indexInAlphabet] = new TrieNode<Word *>(
                    new Word(word.getText().substr(0, i + 1)),
                    i == word.length() - 1,
                    this->alphabet.length()
            );
        } else if (i == word.length() - 1) {
            current->children[indexInAlphabet]->isTerminal = true;
        }

        current = current->children[indexInAlphabet];
    }
}

void
Trie::recursiveAutocomplete(
        TrieNode<Word *> *currentWord,
        Word **suggestions,
        unsigned int &wordCount,
        unsigned int maxWords,
        unsigned int &depth,
        unsigned int maxDepth
) const {
    if (currentWord == nullptr) return;

    for (unsigned int i = 0; i < this->alphabet.length(); i++) {
        if (currentWord->children[i] == nullptr) continue;

        if (currentWord->children[i]->isTerminal) {
            suggestions[wordCount] = currentWord->children[i]->data;
            wordCount++;

            if (wordCount >= maxWords) {
                return;
            }
        }
    }

    depth++;

    if (depth >= maxDepth) {
        return;
    }

    for (unsigned int i = 0; i < this->alphabet.length(); i++) {
        recursiveAutocomplete(currentWord->children[i], suggestions, wordCount, maxWords,
                              depth, maxDepth);
    }
}

Word *Trie::search(const string &word) const {
    auto current = this->root;

    for (auto i: word) {
        int indexInAlphabet = Utils::getIndexInAlphabet(i, this->alphabet);

        if (current->children[indexInAlphabet] == nullptr) {
            return nullptr;
        }

        current = current->children[indexInAlphabet];
    }

    if (!current->isTerminal) {
        return nullptr;
    }

    return current->data;
}

Word **Trie::autocomplete(const string &word, unsigned int maxWords, unsigned int maxDepth) const {
    auto current = this->root;

    auto *suggestions = Utils::initArray<Word *>(nullptr, maxWords);
    unsigned int wordCount = 0;

    for (auto i: word) {
        int indexInAlphabet = Utils::getIndexInAlphabet(i, this->alphabet);

        if (current->children[indexInAlphabet] == nullptr) {
            return suggestions;
        }

        current = current->children[indexInAlphabet];
    }

    unsigned int depth = 0;
    recursiveAutocomplete(current, suggestions, wordCount, maxWords, depth, maxDepth);

    return suggestions;
}

ostream &operator<<(ostream &os, const Trie &t) {
    return os;
}
