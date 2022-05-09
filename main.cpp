#include <iostream>
#include "Word.h"

using namespace std;

/**
 * Main program
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char const *argv[]) {
    Language fr = Language("fr");

    Word w1 = Word("book", fr);
    Word w2 = Word("back", fr);

    cout << w1.getLevenshteinDistance(w2);
    return 0;
}
