//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include <utility>
#include "Language.h"

using namespace std;

class Word {
private:
    string content;
    Language *language;

public:
    explicit Word(string content, Language *language) : content(std::move(content)), language(language) {}

    explicit Word(string content) : Word(std::move(content), nullptr) {}

    ~Word();

    Language *getLanguage() const { return this->language; }

    void setLanguage(Language *language) { this->language = language; }

    string getContent() const { return this->content; }

    unsigned int getLength() const { return this->content.size(); }

    void setContent(string content) { this->content = content; }

    unsigned int levenshteinDistance(Word &word);

    friend bool operator==(const Word &left, const Word &right);

    friend bool operator<(const Word &left, const Word &right);

    friend ostream &operator<<(ostream &os, const Word &t);
};
