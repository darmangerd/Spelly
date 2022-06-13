#include <iostream>
#include <array>
#include "word/Word.h"
#include "trie/Trie.h"
#include "correction/Correction.h"
#include "gui/Interaction.h"

using namespace std;

void levenshteinDistance(const string &word1, const string &word2) {
    Word w1 = Word(word1);
    Word w2 = Word(word2);

    cout << "The Levenshtein distance between \"" << word1 << "\" and \"" << word2 << "\" is: "
         << w1.levenshteinDistance(w2) << endl;
}

void searchInTrie(const string &word, const Trie &t) {
    cout << "Searching for \"" << word << "\"..." << endl;
    auto found = t.search(word);

    if (found == nullptr) {
        cout << "Word \"" << word << "\" not found" << endl;
    } else {
        cout << "Word \"" << *found << "\" exists" << endl;
    }
}

void autosuggest(const string &word, const Trie &t) {
    cout << "Autocompleting: \"" << word << "\"..." << endl;

    unsigned int maxWords = 9;
    auto suggestions = t.autocomplete(word, maxWords);

    for (unsigned int i = 0; i < maxWords; i++) {
        if (suggestions[i] != nullptr) {
            cout << i + 1 << ") " << suggestions[i]->getText() << endl;
        } else {
            cout << i + 1 << ") empty suggestion" << endl;
        }
    }
}

void correct(const string &word, Correction &c, Trie &t) {
    auto candidates = c.findCandidates(word);
    auto found = t.search(word);

    cout << "Looking for candidates for the word \"" << word << "\"..." << endl;
    if (found != nullptr) {
        cout << word << " is correct " << endl;
        return;
    }

    cout << "Candidates for \"" << word << "\" correction:" << endl;
    for (auto candidate: candidates) {
        cout << "   - " << *candidate.first << " (distance of " << candidate.second << ")" << endl;
    }
}

int main() {
    // Create a Trie with the words in the file
    string filePath = "french.txt";
    cout << "Creating Trie for dictionary: " << filePath << "... ";

    vector<Word *> words;
    auto insertToWords = [&](const string &line, long index) {
        words.emplace_back(new Word(line));
    };
    Utils::readFileLineByLine(filePath, insertToWords);
    string alphabet = Utils::extractSymbolsFromFile(filePath);

    Correction c(words, 128);
    Trie t(alphabet, words);

    cout << "done" << endl << endl;

    // Interaction with the user for writing words
    string finalText;
    string userInput;
    do {
        finalText = Interaction::run(t, c);
        cout << endl << "Final text: " << finalText << endl;

        cout << endl << "Do you want to restart? (y/n)" << endl;
        cin >> userInput;
    } while (userInput == "y");

    // correct("asjdhg", c, t);

    // cout << endl;

    // searchInTrie("clément", t);
    // searchInTrie("asd", t);

    // cout << endl;

    // autosuggest("dé", t);
    // autosuggest("daaaaé", t);

    return EXIT_SUCCESS;
}