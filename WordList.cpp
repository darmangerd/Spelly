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
int** getLevenshteinMatrix(Word &word){
    int** matrix = new int*[word.getSize() + 1];
    for (int i = 0; i < word.getSize() + 1; i++) {
        matrix[i] = new int[word.getSize() + 1];
    }
    for (int i = 0; i < word.getSize() + 1; i++) {
        for (int j = 0; j < word.getSize() + 1; j++) {
            matrix[i][j] = 0;
        }
    }


}
const Word &WordList::getNearestWords(Word word, int maxWords) const {

}
