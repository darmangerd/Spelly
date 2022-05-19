//
// Created by owen on 19.05.22.
//

#include <sstream>
#include "Utils.h"

void Utils::readFile(const string &path, void f(const string&, unsigned int)) {
    ifstream infile(path);

    if (!infile) {
        throw runtime_error("File " + path + " couldn't be opened");
    }

    string line;
    unsigned int count = 0;
    while (getline(infile, line)) {
        f(line, count);
        count++;
    }
}

string Utils::getAlphabet(int max) {
    stringstream ss;

    for (int i = 0; i < max; i++) {
        ss << Utils::getLetterFromAlphabetIndex(i);

        if (i < max - 1) {
            ss << endl;
        }
    }

    return ss.str();
}

int Utils::getIndexInAlphabet(char letter) {
    return tolower(letter) - 'a';
}

char Utils::getLetterFromAlphabetIndex(int letterIndex) {
    return toupper((char) (letterIndex + 'a'));
}
