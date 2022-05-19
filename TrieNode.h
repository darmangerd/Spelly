//
// Created by clemsou on 12.05.2022.
//

#pragma once

#include <utility>
#include <vector>
#include <string>

#define ALPHABET_SIZE 26
using namespace std;

template<class T>
class TrieNode {
public:
    TrieNode(T data, bool isTerminal) : data(data), isTerminal(isTerminal) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            this->children[i] = nullptr;
        }
    }

    TrieNode() : TrieNode(nullptr, false) {}

    TrieNode<T> *parent;
    TrieNode<T> *children[ALPHABET_SIZE];
    T data;
    bool isTerminal{};
};
