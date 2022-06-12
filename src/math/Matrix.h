//
// Created by owen on 05.05.22.
//

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Matrix {
private:
    T **matrix_;
    unsigned long columns_;
    unsigned long rows_;

public:

    /**
     * Declare a matrix_ with a default value
     * @param rows The number of desired rows_
     * @param columns The number of desired columns_
     * @param defaultValue The value of each element in the matrix_
     */
    Matrix(const unsigned long rows, const unsigned long columns, T defaultValue) : columns_(columns), rows_(rows) {
        this->matrix_ = new T *[rows];

        for (unsigned int rowIndex = 0; rowIndex < rows; rowIndex++) {
            this->matrix_[rowIndex] = new T[columns];

            for (unsigned int columnIndex = 0; columnIndex < columns; columnIndex++) {
                this->matrix_[rowIndex][columnIndex] = defaultValue;
            }
        }
    }

    /**
     * Declare a matrix_ with a function based on the columnIndex and the rowIndex, it should returns the value of the element at M(i, j)
     * @tparam F The function type
     * @param rows The number of desired rows_
     * @param columns The number of desired columns_
     * @param f The function that returns the value of the element at M(i, j)
     */
    template<typename F>
    Matrix(const unsigned long rows, const unsigned long columns, F &f) : columns_(columns), rows_(rows) {
        this->matrix_ = new T *[rows];

        for (unsigned int rowIndex = 0; rowIndex < rows; rowIndex++) {
            this->matrix_[rowIndex] = new T[columns];

            for (unsigned int columnIndex = 0; columnIndex < columns; columnIndex++) {
                this->matrix_[rowIndex][columnIndex] = f(rowIndex, columnIndex);
            }
        }
    }

    ~Matrix() = default;

    /**
     * Get the element of the matrix_ at M(columnIndex, rowIndex)
     * @param columnIndex The column index (x)
     * @param rowIndex The row index (y)
     * @return The item at M(columnIndex, rowIndex)
     */
    [[nodiscard]] T get(unsigned long columnIndex, unsigned long rowIndex) const {
        return this->matrix_[rowIndex][columnIndex];
    }

    /**
     * Set the item positioned at M(columnIndex, rowIndex)
     * @param columnIndex The column index (x)
     * @param rowIndex The row index (y)
     * @param value The value
     */
    void set(unsigned long columnIndex, unsigned long rowIndex, T value) {
        this->matrix_[rowIndex][columnIndex] = value;
    }

    /**
     * Get the number of columns_ of the matrix_
     * @return The number of columns_ of the matrix_
     */
    [[nodiscard]] unsigned long getWidth() const {
        return columns_;
    }

    /**
     * Get the number of rows_ of the matrix_
     * @return The number of rows_ of the matrix_
     */
    [[nodiscard]] unsigned long getHeight() const {
        return rows_;
    }

    [[nodiscard]] string toString() const {
        stringstream ss;

        ss << "Matrix dimensions: " << this->columns_ << "x" << this->rows_ << endl;

        for (int rowIndex = 0; rowIndex < this->rows_; rowIndex++) {
            for (int columnIndex = 0; columnIndex < this->columns_; columnIndex++) {
                ss << this->get(columnIndex, rowIndex) << " ";
            }
            ss << endl;
        }

        return ss.str();
    }

    friend ostream &operator<<(ostream &os, const Matrix<T> &matrix) {
        os << matrix.toString();
        return os;
    }
};
