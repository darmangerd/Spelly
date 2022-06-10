//
// Created by david.darmange on 10.06.2022.
//

#include "interaction.h"

const string interaction::QUIT_KEY = "/exit";


void interaction::check(string &word, Trie &t, Correction &c) {
    auto candidates = c.findCandidates(word);
    auto found = t.search(word);
    unsigned int maxWords = 4;
    auto suggestions = t.autocomplete(word, maxWords);
    //unsigned int i = 0;

    if (found == nullptr) {
        cout << "\nCorrection : \"" << word << "\", candidates :" << endl;
        for (int i = 0; i <= maxWords; i++) {
            auto candidate = candidates[i];
            cout << i << ") "  << *candidate.first << " (distance of " << candidate.second << ")" << endl;
        }
    }

    cout << "\nAutocompleting : \"" << word << "\"..." << endl;
    for (int i = maxWords+1; i <= (maxWords*2)+1; i++) {
        if (suggestions[i-maxWords] != nullptr) {
            cout << i << ") " << suggestions[i-maxWords]->getText() << endl;

        } else {
            cout << i << ") empty suggestion" << endl;
        }
    }

    int index = 0;
    do
    {
        cout << "Enter the number of the word you want to use: " << endl;
        cin >> index;

    } while (index < 0 || index > maxWords*2+1);

    if(index < maxWords+1) {
        auto candidate = candidates[index];
        word = candidate.first->getText();
    }
    else {
        word = suggestions[index-maxWords]->getText();
    }
}

string interaction::run(Trie &t, Correction &c) {
    cout << "-- Welcome to Spelly the word checker --\n" << endl;
    string text = "";
    string word = "";
    for (;;) {
        cout << "Enter a word to check : ";
        cin >> word;
        if(word != QUIT_KEY) {
            check(word, t, c);
            text += word;
            word = "";
        }
        else {
            break;
        }
    }
    return text + ".";
}