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
    TrieNode<T> *parent;
    TrieNode<T> **children;
    T data;
    bool isTerminal = false;
    unsigned int alphabetSize = 26;

    void initChildren() {
        this->children = new TrieNode<T> *[this->alphabetSize];
        for (unsigned int i = 0; i < this->alphabetSize; ++i) {
            this->children[i] = nullptr;
        }
    }

public:
    TrieNode(T data, bool isTerminal, unsigned int alphabetSize) : data(data), isTerminal(isTerminal),
                                                                   alphabetSize(alphabetSize) {
        initChildren();
    }

    TrieNode() : TrieNode(nullptr, false, 26) {
        initChildren();
    }

    ~TrieNode() {
        for (unsigned int i = 0; i < this->alphabetSize; ++i) {
            if (this->children[i] != nullptr) {
                delete this->children[i];
            }
        }

        delete this->children;
    }

    TrieNode<T> *getParent() const {
        return this->parent;
    }

    TrieNode<T> **getChildren() const {
        return this->children;
    }

    TrieNode<T> *getChild(unsigned int index) const {
        return this->children[index];
    }

    void setChild(unsigned int index, TrieNode<T> *child) {
        this->children[index] = child;
    }

    T getData() const {
        return this->data;
    }

    bool getIsTerminal() const {
        return this->isTerminal;
    }

    void setIsTerminal(bool isTerminal) {
        this->isTerminal = isTerminal;
    }

    void setAlphabetSize(unsigned int alphabetSize) {
        this->alphabetSize = alphabetSize;
        initChildren();
    }
};
