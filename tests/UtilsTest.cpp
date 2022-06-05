//
// Created by owen on 05.06.22.
//

#include <array>
#include "gtest/gtest.h"
#include "../src/misc/Utils.h"

TEST(Utils, shouldInitAnArrayWithDefaultValue1) {
    unsigned int size = 10;
    unsigned int defaultValue = 0;
    auto arr = Utils::initializeArray(size, defaultValue);

    for (unsigned int i = 0; i < size; i++) {
        EXPECT_EQ(arr[i], defaultValue);
    }
}

TEST(Utils, shouldInitAnArrayWithDefaultValue2) {
    unsigned int size = 20;
    string defaultValue = "hello";

    auto arr = Utils::initializeArray(size, defaultValue);

    for (unsigned int i = 0; i < size; i++) {
        EXPECT_EQ(arr[i], defaultValue);
    }
}

TEST(Utils, shouldInitAnArrayWithFunction1) {
    unsigned int size = 20;
    auto f = [](unsigned int index) {
        return index;
    };

    auto arr = Utils::initializeArray<unsigned int>(size, f);

    for (unsigned int i = 0; i < size; i++) {
        EXPECT_EQ(arr[i], i);
    }
}

TEST(Utils, shouldInitAnArrayWithFunction2) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    auto size = alphabet.size();
    auto f = [&alphabet](unsigned int index) {
        return alphabet[index];
    };

    auto arr = Utils::initializeArray<char>(size, f);

    for (unsigned int i = 0; i < size; i++) {
        EXPECT_EQ(arr[i], alphabet[i]);
    }
}

TEST(Utils, shouldOpenFile) {
    EXPECT_NO_THROW(Utils::openFile("test.txt"));
}

TEST(Utils, shouldReadFileLineByLine) {
    vector<string> lines;
    vector<string> predictedLines{
            "a",
            "ab",
            "abc",
            "abcd",
            "abcde"
    };

    auto f = [&lines](const string &line, long count) { lines.emplace_back(line); };
    Utils::readFileLineByLine("test.txt", f);

    for (unsigned int i = 0; i < max(lines.size(), predictedLines.size()); i++) {
        EXPECT_EQ(lines[i], predictedLines[i]);
    }
}

TEST(Utils, shouldReadFileCharByChar) {
    string text;
    string predictedText = "a\nab\nabc\nabcd\nabcde\n";

    auto f = [&text](const char &c, long count) { text += c; };
    Utils::readFileCharByChar("test.txt", f);

    EXPECT_EQ(text, predictedText);
}

TEST(Utils, shouldExtractSymbolsFromFile) {
    string text;
    string predictedText = "abcde";

    text = Utils::extractSymbolsFromFile("test.txt");

    EXPECT_EQ(text, predictedText);
}

TEST(Utils, shouldCreateASliceOfVector) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector vs1 = Utils::sliceVector(v, 0, 3);
    vector vp1{1, 2, 3, 4};

    EXPECT_EQ(vs1, vp1);
}

TEST(Utils, shouldCreateChunksFromVector1) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char numberOfChunks = 3;

    auto chunks = Utils::createChunks(v, numberOfChunks);

    vector<vector<int>> predictedChunks{
            vector{1, 2, 3},
            vector{4, 5, 6},
            vector{7, 8, 9, 10},
    };

    EXPECT_EQ(chunks, predictedChunks);
}

TEST(Utils, shouldCreateChunksFromVector2) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char numberOfChunks = 10;

    auto chunks = Utils::createChunks(v, numberOfChunks);

    vector<vector<int>> predictedChunks{
            vector{1},
            vector{2},
            vector{3},
            vector{4},
            vector{5},
            vector{6},
            vector{7},
            vector{8},
            vector{9},
            vector{10},
    };

    EXPECT_EQ(chunks, predictedChunks);
}

TEST(Utils, shouldCreateChunksFromVector3) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char numberOfChunks = 11;

    auto chunks = Utils::createChunks(v, numberOfChunks);

    vector<vector<int>> predictedChunks{
            vector{1},
            vector{2},
            vector{3},
            vector{4},
            vector{5},
            vector{6},
            vector{7},
            vector{8},
            vector{9},
            vector{10},
    };

    EXPECT_EQ(chunks, predictedChunks);
}

TEST(Utils, shouldCreateChunksFromVector4) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char numberOfChunks = 9;

    auto chunks = Utils::createChunks(v, numberOfChunks);

    vector<vector<int>> predictedChunks{
            vector{1},
            vector{2},
            vector{3},
            vector{4},
            vector{5},
            vector{6},
            vector{7},
            vector{8},
            vector{9, 10}
    };

    EXPECT_EQ(chunks, predictedChunks);
}
