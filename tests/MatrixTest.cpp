//
// Created by owen on 05.06.22.
//

#include "gtest/gtest.h"
#include "../src/math/Matrix.h"

using namespace testing;

TEST(Matrix, shouldCreateAMatrixWithDefaultValue1) {
    int defaultValue = 10;

    Matrix m(10, 3, defaultValue);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            EXPECT_EQ(m.get(columnIndex, rowIndex), defaultValue);
        }
    }
}

TEST(Matrix, shouldCreateAMatrixWithDefaultValue2) {
    int defaultValue = 0;

    Matrix m(3, 10, defaultValue);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            EXPECT_EQ(m.get(columnIndex, rowIndex), defaultValue);
        }
    }
}

TEST(Matrix, shouldCreateAMatrixWithFunction1) {
    auto f = [](unsigned int columnIndex, unsigned int rowIndex) {
        if (columnIndex == rowIndex) return 1;
        return 0;
    };

    Matrix<unsigned int> m(10, 10, f);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            if (rowIndex == columnIndex) EXPECT_EQ(m.get(columnIndex, rowIndex), 1);
            else EXPECT_EQ(m.get(columnIndex, rowIndex), 0);
        }
    }
}

TEST(Matrix, shouldCreateAMatrixWithFunction2) {
    auto f = [](unsigned int columnIndex, unsigned int rowIndex) {
        return columnIndex * rowIndex;
    };

    Matrix<unsigned int> m(3, 10, f);

    cout << m;

    for (int columnIndex = 0; columnIndex < m.getWidth(); columnIndex++) {
        for (int rowIndex = 0; rowIndex < m.getHeight(); rowIndex++) {
            EXPECT_EQ(m.get(columnIndex, rowIndex), rowIndex * columnIndex);
        }
    }
}
