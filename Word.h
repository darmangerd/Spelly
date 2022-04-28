//
// Created by clemsou on 28.04.2022.
//

#ifndef SPELLY_WORD_H
#define SPELLY_WORD_H
#include <iostream>
class Word {
public:
    Word(std::string content, std::string language);
    ~Word();
    std::string getLanguage() const;
    void setLanguage(std::string word);
    std::string getContent() const;
    void setContent(std::string word);
    int getLevenshteinDistance(Word word);
private:
    std::string content;
    std::string language;
};
#endif //SPELLY_WORD_H
