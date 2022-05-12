//
// Created by clemsou on 12.05.2022.
//

#ifndef SPELLY_TRIENODE_H
#define SPELLY_TRIENODE_H
#include <vector>
#include <string>
#define ALPHABETS 26
#define MAX_WORD_LENGTH 100
using namespace std;
class TrieNode {
    public:
    TrieNode* parent;
    TrieNode* children[ALPHABETS];
    string word;
    vector<int> distance;
};
#endif //SPELLY_TRIENODE_H
