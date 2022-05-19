//
// Created by owen on 05.05.22.
//

#include "Word.h"
#include "../math/Matrix.h"

Word::~Word() {

}

unsigned int Word::getLevenshteinDistance(Word &word) {
    auto m = Matrix<unsigned int>(word.content.length() + 1, this->content.length() + 1, 0);

    for (unsigned int i = 1; i < this->getLength() + 1; ++i) {
        m.set(i, 0, i);
    }

    for (unsigned int j = 1; j < word.getLength() + 1; ++j) {
        m.set(0, j, j);
    }

    for (unsigned int i = 1; i < this->getLength() + 1; ++i) {
        for (unsigned int j = 1; j < word.getLength() + 1; ++j) {
            if (this->content[i - 1] == word.content[j - 1]) {
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

    return m.get(this->getLength(), word.getLength());
}

bool operator==(const Word &left, const Word &right) {
    return (
        left.content == right.content &&
        left.language->getName() == right.language->getName()
    );
}

bool operator<(const Word &left, const Word &right) {
    return left.content.length() < right.content.length();
}

ostream &operator<<(ostream &os, const Word &w) {
    os << w.getContent() << " (" << w.getLanguage()->getName() << ")";
    return os;
}

