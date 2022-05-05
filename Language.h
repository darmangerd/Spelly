//
// Created by owen on 05.05.22.
//

#pragma one

#include <string>

using namespace std;

class Language {
private:
    string name;

public:
    explicit Language(string name) : name(name) {}

    string getName() const { return this->name; }

    void setName(string name) { this->name = name; }
};
