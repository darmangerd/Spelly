//
// Created by owen on 05.06.22.
//

#include "gtest/gtest.h"
#include "../src/math/Matrix.h"

using namespace testing;

TEST(Matrix, shouldCreateAMatrix1) {
    int defaultValue = 10;

    Matrix m(10, 3, defaultValue);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            EXPECT_EQ(m.get(columnIndex, rowIndex), defaultValue);
        }
    }
}

TEST(Matrix, shouldCreateAMatrix2) {
    int defaultValue = 0;

    Matrix m(3, 10, defaultValue);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            EXPECT_EQ(m.get(columnIndex, rowIndex), defaultValue);
        }
    }
}
