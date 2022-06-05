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
    unsigned int columns;
    unsigned int rows;

public:
    Matrix(const unsigned int rows, const unsigned int columns, T defaultValue) : columns(columns), rows(rows) {
        this->matrix = new T *[rows];

        for (unsigned int rowIndex = 0; rowIndex < rows; rowIndex++) {
            this->matrix[rowIndex] = new T[columns];

            for (unsigned int columnIndex = 0; columnIndex < columns; columnIndex++) {
                this->matrix[rowIndex][columnIndex] = defaultValue;
            }
        }
    }

    ~Matrix() {
        for (int rowIndex = 0; rowIndex < this->rows; rowIndex++) {
            delete[] this->matrix[rowIndex];
        }
        delete[] this->matrix;
    }

    T get(unsigned int columnIndex, unsigned int rowIndex) const {
        return this->matrix[rowIndex][columnIndex];
    }

    void set(unsigned int columnIndex, unsigned int rowIndex, T value) {
        this->matrix[rowIndex][columnIndex] = value;
    }

    unsigned int getWidth() const {
        return columns;
    }

    unsigned int getHeight() const {
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

    template<typename U>
    friend ostream &operator<<(ostream &os, const Matrix<U> &matrix) {
        os << matrix.toString();
        return os;
    }
};
