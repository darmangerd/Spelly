//
// Created by owen on 05.06.22.
//

#include "gtest/gtest.h"
#include "../src/word/Word.h"

TEST(Word, levenshteinDistance2) {
    Word w1("a");
    Word w2("b");

    unsigned int distance = 1;

    EXPECT_EQ(w1.levenshteinDistance(w2), distance);
    EXPECT_EQ(w2.levenshteinDistance(w1), distance);
}

TEST(Word, levenshteinDistance1) {
    Word w1("back");
    Word w2("book");

    unsigned int distance = 2;

    EXPECT_EQ(w1.levenshteinDistance(w2), distance);
    EXPECT_EQ(w2.levenshteinDistance(w1), distance);
}

TEST(Word, levenshteinDistance3) {
    Word w1("back");
    Word w2("back");

    unsigned int distance = 0;

    EXPECT_EQ(w1.levenshteinDistance(w2), distance);
    EXPECT_EQ(w2.levenshteinDistance(w1), distance);
}

TEST(Word, levenshteinDistance4) {
    Word w1("aaa");
    Word w2("bbb");

    unsigned int distance = 3;

    EXPECT_EQ(w1.levenshteinDistance(w2), distance);
    EXPECT_EQ(w2.levenshteinDistance(w1), distance);
}

TEST(Word, levenshteinDistance5) {
    Word w1("aba");
    Word w2("bbb");

    unsigned int distance = 2;

    EXPECT_EQ(w1.levenshteinDistance(w2), distance);
    EXPECT_EQ(w2.levenshteinDistance(w1), distance);
}
