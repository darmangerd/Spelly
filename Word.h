//
// Created by clemsou on 28.04.2022.
//

#pragma once

#include <iostream>
#include "Language.h"

using namespace std;

class Word {
private:
    string content;
    Language language;

public:
    Word(string content, Language language) : content(move(content)), language(move(language)) {}

    ~Word();

    const Language &getLanguage() const { return this->language; }

    void setLanguage(Language language) { this->language = language; }

    string getContent() const { return this->content; }

    unsigned int getSize() const { return this->content.size(); }

    void setContent(string content) { this->content = content; }

    unsigned int getLevenshteinDistance(Word &word);

    friend bool operator==(const Word &left, const Word &right);

    friend bool operator<(const Word &left, const Word &right);
};
