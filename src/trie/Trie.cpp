//
// Created by owen on 09.05.22.
//

#include "Trie.h"

Trie::Trie(const string &path) {
    this->root = new TrieNode<Word *>(nullptr, false);

    ifstream infile(path);

    if (!infile) {
        throw runtime_error("File " + path + " couldn't be opened");
    }

    string line;
    unsigned int count = 0;
    auto l = new Language("fr");

    while (getline(infile, line)) {
        this->insert(Word(line, l));
        count++;
    }
}

void Trie::insert(const Word &word) const {
    auto current = this->root;

    for (unsigned int i = 0; i < word.getLength(); i++) {
        int indexInAlphabet = Utils::getIndexInAlphabet(word.getContent()[i]);

        if (current->children[indexInAlphabet] == nullptr) {
            current->children[indexInAlphabet] = new TrieNode<Word *>(
                    new Word(word.getContent().substr(0, i + 1), word.getLanguage()),
                    i == word.getLength() - 1);
        } else if (i == word.getLength() - 1) {
            current->children[indexInAlphabet]->isTerminal = true;
        }

        current = current->children[indexInAlphabet];
    }
}

Word *Trie::search(const string &word) const {
    auto current = this->root;

    for (char i : word) {
        int indexInAlphabet = Utils::getIndexInAlphabet(i);

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

ostream &operator<<(ostream &os, const Trie &t) {
    return os;
}
