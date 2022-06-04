//
// Created by owen on 19.05.22.
//

#include <sstream>
#include <vector>
#include <set>
#include <array>
#include "Utils.h"

array<char, 26> Utils::getAlphabet(int max) {
    array<char, 26> alphabet{};

    for (int i = 0; i < max; i++) {
        alphabet[i] = Utils::getLetterFromAlphabetIndex(i);
    }

    return alphabet;
}

int Utils::getIndexInAlphabet(char letter) {
    return tolower(letter) - 'a';
}

int Utils::getIndexInAlphabet(char letter, string alphabet) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (tolower(alphabet[i]) == tolower(letter)) {
            return i;
        }
    }

    return -1;
}

char Utils::getLetterFromAlphabetIndex(int letterIndex) {
    return (char) (letterIndex + 'a');
}

string Utils::extractSymbolsFromFile(const string &path) {
    set<char> symbols;
    auto alphabet = Utils::getAlphabet();

    auto addCharToSymbols = [&symbols](char c, long index) {
        if (c != '\n') {
            symbols.insert(tolower(c));
        }
    };

    Utils::readFileCharByChar(path, addCharToSymbols);

    for (char i: alphabet) {
        symbols.insert(i);
    }

    string res;
    for_each(symbols.begin(), symbols.end(), [&res](char c) -> void { res += c; });

    return res;
}

ifstream Utils::openFile(const string &path) {
    ifstream infile(path);

    if (!infile) {
        throw runtime_error("File " + path + " couldn't be opened");
    }

    return infile;
}
