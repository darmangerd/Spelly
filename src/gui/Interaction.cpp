//
// Created by david.darmange on 10.06.2022.
//

#include "Interaction.h"

const string Interaction::QUIT_KEY = "/exit";

string Interaction::check(string &word, Trie &t, Correction &c) {
    auto candidates = c.findCandidates(word);
    auto found = t.search(word);
    int maxWords = 4;
    auto suggestions = t.autocomplete(word, maxWords);

    // Correction
    int minCandidate = min(maxWords, int(candidates.size()));

    if (found == nullptr) {
        cout << endl << "Correction : \"" << word << "\", candidates :" << endl;
        for (int i = 0; i < minCandidate; i++) {
            auto candidate = candidates[i];
            cout << i << ") " << *candidate.first << " (distance of " << candidate.second << ")" << endl;
        }
    }

    // Autocomplete
    cout << endl << "Autocompleting : \"" << word << "\"..." << endl;
    int minAutoComplete = min(maxWords, int(sizeof(suggestions)));
    for (int i = 0; i < minAutoComplete; i++) {
        if (suggestions[i] != nullptr) {
            cout << i + minCandidate << ") " << suggestions[i]->getText() << endl;
        } else {
            cout << i + minCandidate << ") empty suggestion" << endl;
        }
    }

    // Get user input for correction/autocomplete
    int index = 0;
    do {
        cout << "Enter the number of the correction you want : ";
        cin >> index;

    } while (index < 0 || index > minCandidate + minAutoComplete);

    if (index < minCandidate) {
        auto candidate = candidates[index];
        return candidate.first->getText();
    } else {
        return suggestions[index - minCandidate]->getText();
    }
}

string Interaction::run(Trie &t, Correction &c) {
    cout << "-- Welcome to Spelly the word checker --" << endl;
    cout << "- Write a word to correct/autocomplete " << endl;
    cout << "- Write \"/exit\" to quit and get your corrected text" << endl;
    string text = "";
    string word = "";
    for (;;) {
        cout << "Enter a word to check : ";
        cin >> word;
        if (word != QUIT_KEY) {
            text += check(word, t, c);
            text += " ";
        } else {
            break;
        }
    }
    return text + ".";
}