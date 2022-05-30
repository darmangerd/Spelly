//
// Created by clemsou on 12.05.2022.
//

#pragma once

#include <utility>
#include <vector>
#include <string>

using namespace std;

template<class T>
class TrieNode {
private:
    unsigned int alphabetSize = 26;

    void initChildren() {
        this->children = new TrieNode<T>* [this->alphabetSize];
        for (unsigned int i = 0; i < this->alphabetSize; ++i) {
            this->children[i] = nullptr;
        }
    }

public:
    TrieNode(T data, bool isTerminal) : data(data), isTerminal(isTerminal) {
        initChildren();
    }

    TrieNode(T data, bool isTerminal, unsigned int alphabetSize) : data(data), isTerminal(isTerminal),
                                                                    alphabetSize(alphabetSize) {
        initChildren();
    }

    TrieNode() : TrieNode(nullptr, false, 26) {
        initChildren();
    }

    void setAlphabetSize(unsigned int alphabetSize) {
        this->alphabetSize = alphabetSize;
        initChildren();
    }

    TrieNode<T> *parent;
    TrieNode<T> **children;
    T data;
    bool isTerminal = false;
};
