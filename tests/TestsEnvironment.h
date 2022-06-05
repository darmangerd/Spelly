//
// Created by owen on 05.06.22.
//

#pragma one

#include "gtest/gtest.h"
#include "../src/trie/Trie.h"
#include "../src/correction/Correction.h"

using namespace testing;

class TestsEnvironment : public Environment {
public:
    static Trie *trie;
    static Correction *correction;

    void SetUp() override {
        TestsEnvironment::trie = nullptr;

        string filePath = "french.txt";

        vector<Word *> words;
        auto insertToWords = [&](const string &line, long index) {
            words.emplace_back(new Word(line));
        };
        Utils::readFileLineByLine(filePath, insertToWords);
        string alphabet = Utils::extractSymbolsFromFile(filePath);

        TestsEnvironment::trie = new Trie(alphabet, words);
        TestsEnvironment::correction = new Correction(words, 10);
    }

    void TearDown() override {
        delete TestsEnvironment::trie;
    }
};

Trie *TestsEnvironment::trie;
Correction *TestsEnvironment::correction;
