//
// Created by david.darmange on 10.06.2022.
//

#ifndef SPELLY_INTERACTION_H
#define SPELLY_INTERACTION_H
#include <iostream>
#include <string>
#include <fstream>
#include "../word/Word.h"
#include "../trie/Trie.h"
#include "../correction/Correction.h"
#include <stdio.h>
#include <string.h>
using namespace std;
class interaction {
public:
    /**
     * @brief Runs the interaction with the user.
     * @param t Trie to use for searching.
     * @param c Correction to use for corrections.
     */
    static string run(Trie &t, Correction &c);

private:
    static const string QUIT_KEY;

    /**
     * @brief Run the correct and autosuggest process.
     * @param word The word to check.
     * @param t Trie to use for searching.
     * @param c Correction to use for corrections.
     */
    static void check(string &word, Trie &t, Correction &c);
};


#endif //SPELLY_INTERACTION_H
