//
// Created by david.darmange on 10.06.2022.
//

#include "Interaction.h"

const string Interaction::QUIT_KEY = "/exit";

string Interaction::check(string &word, Trie &t, Correction &c) {
    auto candidates = c.findCandidates(word);
    auto found = t.search(word);
    int maxWords = 4;
    bool noCorrect = false;
    bool noSuggest = false;
    auto suggestions = t.autocomplete(word, maxWords);

    // Correction
    cout << endl << "Correcting: \"" << word << "\"..." << endl;
    unsigned int minCandidate = min(maxWords, int(candidates.size()));

    if (found == nullptr) {
        cout << endl << "Correction: \"" << word << "\", candidates :" << endl;
        for (unsigned int i = 0; i < minCandidate; i++) {
            auto candidate = candidates[i];
            cout << i << ") " << *candidate.first << " (distance of " << candidate.second << ")" << endl;
        }
    } else {
        cout << "No correction for: \"" << word << "\", this word is correct" << endl;
        minCandidate = 0;
        noCorrect = true;
    }

    // Autocomplete
    cout << endl << "Autocompleting: \"" << word << "\"..." << endl;
    unsigned int minAutoComplete = min(maxWords, int(sizeof(suggestions)));
    unsigned int countAutocomplete = 0;
    for (unsigned int i = 0; i < minAutoComplete; i++) {
        if (suggestions[i] != nullptr) {
            cout << i + minCandidate << ") " << suggestions[i]->getText() << endl;
            countAutocomplete++;
        }
    }

    if (countAutocomplete <= 0) {
        cout << "No autocompletion available for the word: \"" << word << "\"..." << endl;
        noSuggest = true;
    }

    cout << endl;

    if (noCorrect && noSuggest) {
        return "";
    }

    // Get user input for correction/autocomplete
    unsigned int index = 0;
    while (true) {
        cout << "Enter the number of the correction/autocompletion you want: ";
        if (cin >> index && index >= 0 && index < minCandidate + countAutocomplete) {
            break;
        } else {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << endl << endl;

    if (index < minCandidate) {
        auto candidate = candidates[index];
        return candidate.first->getText();
    } else {
        return suggestions[index - minCandidate]->getText();
    }
}

string Interaction::run(Trie &t, Correction &c) {
    cout << "============ Welcome to Spelly, the word checker ============" << endl;
    cout << "- Write a word to correct/autocomplete" << endl;
    cout << "- Write \"/exit\" to quit and get your corrected text" << endl << endl;

    string text;
    string word;
    while (true) {
        cout << "Enter a word to check: ";
        cin >> word;
        if (word != QUIT_KEY) {
            word = check(word, t, c);
            if (word.empty()){
                cout << endl << "There is no corrections or suggestions for this word" << endl;
            } else {
                text += word;
                text += " ";
            }
        } else {
            break;
        }
    }

    return text;
}