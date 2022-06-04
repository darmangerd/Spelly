//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include <utility>

using namespace std;

class Word {
private:
    string text;

public:
    explicit Word(string text) : text(std::move(text)) {}

    string getText() const { return this->text; }

    unsigned int length() const { return this->text.size(); }

    void setText(string text) { this->text = text; }

    unsigned int levenshteinDistance(Word &word);

    friend bool operator==(const Word &left, const Word &right);

    friend bool operator<(const Word &left, const Word &right);

    friend ostream &operator<<(ostream &os, const Word &t);
};
