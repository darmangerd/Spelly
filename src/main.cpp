#include <iostream>
#include <array>
#include <set>
#include "word/Word.h"
#include "trie/Trie.h"

using namespace std;

Language fr = Language("fr");
Trie t("french.txt");

void levenshteinDistance(const string &word1, const string &word2) {
    Word w1 = Word(word1, &fr);
    Word w2 = Word(word2, &fr);
    cout << w1.getLevenshteinDistance(w2) << endl;
}

void searchInTrie(const string &word) {
    cout << "Searching for \"" << word << "\"..." << endl;
    auto found = t.search(word);

    if (found == nullptr) {
        cout << "Word \"" << word << "\" not found" << endl;
    } else {
        cout << "Word \"" << *found << "\" found" << endl;
    }
}

void autosuggest(const string &word) {
    cout << "Autocompleting: \"" << word << "\"..." << endl;

    unsigned int maxWords = 9;
    auto suggestions = t.autocomplete(word, maxWords);

    for (unsigned int i = 0; i < maxWords; i++) {
        if (suggestions[i] != nullptr) {
            cout << i + 1 << ") " << suggestions[i]->getContent() << endl;
        } else {
            cout << i + 1 << ") empty suggestion" << endl;
        }
    }
}

int main() {
    searchInTrie("clément");

    cout << endl;

    autosuggest("dé");

    return EXIT_SUCCESS;
}
