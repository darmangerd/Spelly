//
// Created by owen on 05.06.22.
//

#include "gtest/gtest.h"
#include "../src/trie/Trie.h"

class TrieEnvironment : public ::testing::Environment {
public:
    static Trie *trie;

    void SetUp() override {
        TrieEnvironment::trie = nullptr;

        string filePath = "french.txt";

        vector<Word *> words;
        auto insertToWords = [&](const string &line, long index) {
            words.emplace_back(new Word(line));
        };
        Utils::readFileLineByLine(filePath, insertToWords);
        string alphabet = Utils::extractSymbolsFromFile(filePath);

        TrieEnvironment::trie = new Trie(alphabet, words);
    }

    void TearDown() override {
        delete TrieEnvironment::trie;
    }
};

Trie *TrieEnvironment::trie;

TEST(Trie, wordShouldExists) {
    Word *w = TrieEnvironment::trie->search("table");
    EXPECT_TRUE(w != nullptr);
}

TEST(Trie, wordShouldNotExists) {
    Word *w = TrieEnvironment::trie->search("thisworddoesnotexists");
    EXPECT_TRUE(w == nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    auto trie = new TrieEnvironment();
    ::testing::AddGlobalTestEnvironment(trie);

    return RUN_ALL_TESTS();
}
