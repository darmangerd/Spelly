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
    TrieNode<T> *parent_;
    TrieNode<T> **children_;
    T data_;
    bool isTerminal_ = false;
    unsigned int alphabetSize_ = 26;

    void initChildren() {
        this->children_ = new TrieNode<T> *[this->alphabetSize_];
        for (unsigned int i = 0; i < this->alphabetSize_; ++i) {
            this->children_[i] = nullptr;
        }
    }

public:
    TrieNode(T data, bool isTerminal, unsigned int alphabetSize) : data_(data), isTerminal_(isTerminal),
                                                                   alphabetSize_(alphabetSize) {
        initChildren();
    }

    TrieNode() : TrieNode(nullptr, false, 26) {
        initChildren();
    }

    ~TrieNode() {
        for (unsigned int i = 0; i < this->alphabetSize_; ++i) {
            if (this->children_[i] != nullptr) {
                delete this->children_[i];
            }
        }

        delete this->children_;
    }

    [[nodiscard]] TrieNode<T> *getParent() const {
        return this->parent_;
    }

    [[nodiscard]] TrieNode<T> **getChildren() const {
        return this->children_;
    }

    [[nodiscard]] TrieNode<T> *getChild(unsigned int index) const {
        return this->children_[index];
    }

    void setChild(unsigned int index, TrieNode<T> *child) {
        this->children_[index] = child;
    }

    [[nodiscard]] T getData() const {
        return this->data_;
    }

    [[nodiscard]] bool getIsTerminal() const {
        return this->isTerminal_;
    }

    void setIsTerminal(bool isTerminal) {
        this->isTerminal_ = isTerminal;
    }

    void setAlphabetSize(unsigned int alphabetSize) {
        this->alphabetSize_ = alphabetSize;
        initChildren();
    }
};
