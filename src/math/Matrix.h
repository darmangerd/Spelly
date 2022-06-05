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
    unsigned int width;
    unsigned int height;

public:
    Matrix(const unsigned int width, const unsigned int height, T defaultValue) : width(width), height(height) {
        this->matrix = new T *[height];

        for (unsigned int x = 0; x < height; ++x) {
            this->matrix[x] = new T[width];

            for (unsigned int y = 0; y < width; ++y) {
                this->matrix[x][y] = defaultValue;
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < this->height; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }

    T get(unsigned int i, unsigned int j) const {
        return this->matrix[i][j];
    }

    void set(unsigned int i, unsigned int j, T value) {
        this->matrix[i][j] = value;
    }

    string toString() const {
        stringstream ss;

        ss << "Matrix dimensions: " << this->width << "x" << this->height << endl;

        for (int i = 0; i < this->height; ++i) {
            for (int j = 0; j < this->width; ++j) {
                ss << this->get(i, j) << " ";
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
