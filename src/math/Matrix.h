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
    T **matrix;
    unsigned long columns;
    unsigned long rows;

public:

    /**
     * Declare a matrix with a default value
     * @param rows The number of desired rows
     * @param columns The number of desired columns
     * @param defaultValue The value of each element in the matrix
     */
    Matrix(const unsigned long rows, const unsigned long columns, T defaultValue) : columns(columns), rows(rows) {
        this->matrix = new T *[rows];

        for (unsigned int rowIndex = 0; rowIndex < rows; rowIndex++) {
            this->matrix[rowIndex] = new T[columns];

            for (unsigned int columnIndex = 0; columnIndex < columns; columnIndex++) {
                this->matrix[rowIndex][columnIndex] = defaultValue;
            }
        }
    }

    /**
     * Declare a matrix with a function based on the columnIndex and the rowIndex, it should returns the value of the element at M(i, j)
     * @tparam F The function type
     * @param rows The number of desired rows
     * @param columns The number of desired columns
     * @param f The function that returns the value of the element at M(i, j)
     */
    template<typename F>
    Matrix(const unsigned long rows, const unsigned long columns, F &f) : columns(columns), rows(rows) {
        this->matrix = new T *[rows];

        for (unsigned int rowIndex = 0; rowIndex < rows; rowIndex++) {
            this->matrix[rowIndex] = new T[columns];

            for (unsigned int columnIndex = 0; columnIndex < columns; columnIndex++) {
                this->matrix[rowIndex][columnIndex] = f(rowIndex, columnIndex);
            }
        }
    }

    ~Matrix() {
        for (int rowIndex = 0; rowIndex < this->rows; rowIndex++) {
            delete[] this->matrix[rowIndex];
        }
        delete[] this->matrix;
    }

    /**
     * Get the element of the matrix at M(columnIndex, rowIndex)
     * @param columnIndex The column index (x)
     * @param rowIndex The row index (y)
     * @return The item at M(columnIndex, rowIndex)
     */
    T get(unsigned long columnIndex, unsigned long rowIndex) const {
        return this->matrix[rowIndex][columnIndex];
    }

    /**
     * Set the item positioned at M(columnIndex, rowIndex)
     * @param columnIndex The column index (x)
     * @param rowIndex The row index (y)
     * @param value The value
     */
    void set(unsigned long columnIndex, unsigned long rowIndex, T value) {
        this->matrix[rowIndex][columnIndex] = value;
    }

    /**
     * Get the number of columns of the matrix
     * @return The number of columns of the matrix
     */
    unsigned long getWidth() const {
        return columns;
    }

    /**
     * Get the number of rows of the matrix
     * @return The number of rows of the matrix
     */
    unsigned long getHeight() const {
        return rows;
    }

    string toString() const {
        stringstream ss;

        ss << "Matrix dimensions: " << this->columns << "x" << this->rows << endl;

        for (int rowIndex = 0; rowIndex < this->rows; rowIndex++) {
            for (int columnIndex = 0; columnIndex < this->columns; columnIndex++) {
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
