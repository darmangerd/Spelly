//
// Created by owen on 19.05.22.
//

#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include "Utils.h"

string Utils::extractSymbolsFromFile(const string &path) {
    set<char> symbols;

    auto addCharToSymbols = [&symbols](char c, long index) {
        if (c != '\n') {
            symbols.insert((char) tolower(c));
        }
    };

    Utils::readFileCharByChar(path, addCharToSymbols);

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
