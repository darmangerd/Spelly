//
// Created by owen on 05.05.22.
//

#include "WordList.h"

WordList::WordList() {
    this->words = set<Word>();
}

WordList::~WordList() {
    delete &this->words;
}

unsigned long WordList::addWord(Word &word) {
    this->words.insert(word);
    return this->words.size();
}

bool WordList::WordExists(Word word) const {
    return this->words.contains(word);
}

const Word &WordList::getNearestWords(Word word, int maxWords) const {

}
