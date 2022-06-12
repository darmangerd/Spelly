//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include <utility>

using namespace std;

class Word {
private:
    string text_;

public:
    explicit Word(string text) : text_(std::move(text)) {}

    [[nodiscard]] string getText() const { return this->text_; }

    [[nodiscard]] unsigned int length() const { return this->text_.size(); }

    void setText(string text) { this->text_ = std::move(text); }

    /**
     * Get the Levenshtein distance with an another word
     * @param word The other word
     * @return The Levenshtein distance between the current and the other word
     */
    unsigned int levenshteinDistance(Word &word);

    friend bool operator==(const Word &left, const Word &right);

    friend bool operator<(const Word &left, const Word &right);

    friend ostream &operator<<(ostream &os, const Word &t);
};
