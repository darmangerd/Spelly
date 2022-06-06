//
// Created by owen on 05.06.22.
//

#include "gtest/gtest.h"
#include "../src/trie/Trie.h"
#include "../src/correction/Correction.h"

using namespace testing;
using namespace std;

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
        delete TestsEnvironment::correction;
    }
};

Trie *TestsEnvironment::trie;
Correction *TestsEnvironment::correction;

TEST(Trie, wordShouldExists) {
    Word *w = TestsEnvironment::trie->search("table");
    EXPECT_NE(w, nullptr);
}

TEST(Trie, wordShouldNotExists) {
    Word *w = TestsEnvironment::trie->search("thisworddoesnotexists");
    EXPECT_EQ(w, nullptr);
}

TEST(Trie, shouldAutocompleteWithXWords) {
    unsigned int nbWords = 10;
    string prefix = "dé";
    auto suggestions = TestsEnvironment::trie->autocomplete(prefix, nbWords);

    for (int i = 0; i < nbWords; ++i) {
        if (suggestions != nullptr) {
            string wordPrefix = suggestions[i]->getText().substr(0, prefix.size());
            EXPECT_EQ(prefix, wordPrefix);
        }
    }
}

TEST(Trie, shouldNotAutocompleteNotFoundWord) {
    unsigned int nbWords = 10;
    string prefix = "thisworddoesnotexists";
    auto suggestions = TestsEnvironment::trie->autocomplete(prefix, nbWords);

    unsigned int incorrect = 0;
    for (int i = 0; i < nbWords; ++i) {
        if (suggestions != nullptr) {
            suggestions += 1;
        }
    }

    EXPECT_EQ(incorrect, 0);
}

TEST(Correction, shouldCorrectWord) {
    Word w("hellp");
    auto candidates = TestsEnvironment::correction->findCandidates(w);
    string predictedCandidates[]{"hello", "help"};

    for (auto c: candidates) {
        EXPECT_EQ(c.first->levenshteinDistance(w), 1);
        EXPECT_EQ(c.second, 1);

        // Verify that the candidate IS IN the predictedArray
        auto found = find(begin(predictedCandidates), end(predictedCandidates), c.first->getText());
        EXPECT_NE(found, end(predictedCandidates));
    }
}

TEST(Correction, shouldReturnTheWordIfExists) {
    string text = "hello";
    auto candidates = TestsEnvironment::correction->findCandidates(text);
    auto candidate = candidates[0];

    EXPECT_EQ(candidate.first->getText(), text);
    EXPECT_EQ(candidate.second, 0);
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);

    auto env = new TestsEnvironment();
    AddGlobalTestEnvironment(env);

    return RUN_ALL_TESTS();
}
