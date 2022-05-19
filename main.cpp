#include <iostream>
#include "Word.h"
#include "Trie.h"

using namespace std;

/**
 * Main program
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char const *argv[]) {
    Language fr = Language("fr");

    Word w1 = Word("book", &fr);
    Word w2 = Word("back", &fr);

    cout << w1.getLevenshteinDistance(w2) << endl;

    string search = "owen";
    Trie t("french.txt");
    auto found = t.search(search);

    if (found == nullptr) {
        cout << "Word \"" << search << "\" not found";
    } else {
        cout << *found << endl;
    }

    return 0;
}
