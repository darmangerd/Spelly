//
// Created by owen on 05.05.22.
//

#include "Word.h"
#include "../math/Matrix.h"

unsigned int Word::levenshteinDistance(Word &word) {
    auto m = Matrix<unsigned int>(word.length() + 1, this->length() + 1, 0);

    for (unsigned int i = 1; i < this->length() + 1; ++i) {
        m.set(i, 0, i);
    }

    for (unsigned int j = 1; j < word.length() + 1; ++j) {
        m.set(0, j, j);
    }

    for (unsigned int i = 1; i < this->length() + 1; ++i) {
        for (unsigned int j = 1; j < word.length() + 1; ++j) {
            if (this->text[i - 1] == word.text[j - 1]) {
                m.set(i, j, m.get(i - 1, j - 1));
            } else {
                auto a = m.get(i, j - 1);
                auto b = m.get(i - 1, j);
                auto c = m.get(i - 1, j - 1);

                if (a <= b && a <= c) {
                    m.set(i, j, a + 1);
                } else if (b <= a && b <= c) {
                    m.set(i, j, b + 1);
                } else {
                    m.set(i, j, c + 1);
                }
            }
        }
    }

    return m.get(this->length(), word.length());
}

bool operator==(const Word &left, const Word &right) {
    return left.getText() == right.getText();
}

bool operator<(const Word &left, const Word &right) {
    return left.text.length() < right.text.length();
}

ostream &operator<<(ostream &os, const Word &w) {
    os << w.getText();
    return os;
}

