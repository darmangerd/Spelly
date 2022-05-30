//
// Created by owen on 19.05.22.
//

#include <sstream>
#include <vector>
#include <set>
#include <array>
#include "Utils.h"

void Utils::readFileLineByLine(const string &path, void f(const string &, uint64_t, void *), void *args) {
    ifstream infile(path);

    if (!infile) {
        throw runtime_error("File " + path + " couldn't be opened");
    }

    string line;
    uint64_t count = 0;
    while (getline(infile, line)) {
        f(line, count, args);
        count++;
    }

    infile.close();
}

void Utils::readFileCharByChar(const string &path, void f(char, uint64_t, void *), void *args) {
    ifstream infile(path);

    if (!infile) {
        throw runtime_error("File " + path + " couldn't be opened");
    }

    char c = 0;
    uint64_t count = 0;
    while (infile.get(c)) {
        f(c, count, args);
        count++;
    }

    infile.close();
}

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

void addCharToSymbols(char c, uint64_t index, set<char> *symbols) {
    if (c != '\n') {
        symbols->insert(tolower(c));
    }
}

string Utils::extractSymbolsFromFile(const string &path) {
    set<char> symbols;
    auto alphabet = Utils::getAlphabet();

    readFileCharByChar(path, reinterpret_cast<void (*)(char, uint64_t, void *)>(addCharToSymbols), &symbols);

    for (char i: alphabet) {
        symbols.insert(i);
    }

    string res;
    for_each(symbols.begin(), symbols.end(), [&res](char c) -> void { res += c; });

    return res;
}
