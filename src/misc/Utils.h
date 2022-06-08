//
//
// Created by owen on 19.05.22.
//

#pragma once

#include <string>
#include <fstream>
#include <set>

using namespace std;

class Utils {
public:
    /**
     * Read a file line by line
     * @tparam F The type of the function that operates on the line
     * @param path The file path
     * @param f Function that operates on the line
     */
    template<typename F>
    static void readFileLineByLine(const string &path, F &f) {
        ifstream file = Utils::openFile(path);

        string line;
        unsigned long count = 0;
        while (getline(file, line)) {
            f(line, count);
            count++;
        }

        file.close();
    }

    /**
     * Read a file char by char
     * @tparam F The type of the function that operates on the line
     * @param path The file path
     * @param f Function that operates on the line
     */
    template<typename F>
    static void readFileCharByChar(const string &path, F &f) {
        ifstream file = Utils::openFile(path);

        char c = 0;
        unsigned long count = 0;
        while (file.get(c)) {
            f(c, count);
            count++;
        }

        file.close();
    }

    /**
     * Init an array of type T with a default value for each element
     * @tparam T The array type
     * @param defaultValue The default value
     * @param size The array size
     * @return The array of type T with the specified size filled with the default value
     */
    template<class T>
    [[nodiscard]] static T *initializeArray(unsigned long size, T defaultValue) {
        T *arr = new T[size];

        for (int i = 0; i < size; i++) {
            arr[i] = defaultValue;
        }

        return arr;
    }

    /**
     * Init an array of type T with a function (with the index) for each element
     * @tparam T The array type
     * @param F The Function type
     * @param f The function that returns the item value
     * @param size The array size
     * @return The array of type T with the specified size filled with the default value
     */
    template<class T, typename F>
    [[nodiscard]] static T *initializeArray(unsigned long size, F &f) {
        T *arr = new T[size];

        for (int i = 0; i < size; i++) {
            arr[i] = f(i);
        }

        return arr;
    }

    /**
     * Create a slice of a vector from a original one, starting from an index and ending at an another one [start, end]
     * @tparam T The type of the elements in the vector
     * @param v The original vector
     * @param start The starting index (included)
     * @param end The ending index (included)
     * @return The sliced vector
     */
    template<class T>
    [[nodiscard]] static vector<T> sliceVector(vector<T> v, unsigned long start, unsigned long end) {
        vector<T> vSlice(end - start + 1);
        copy(v.begin() + start, v.begin() + end + 1, vSlice.begin());

        return vSlice;
    }

    /**
     * Divide a vector into <numberOfChunks> smaller vectors
     * @tparam T The type of the elements in the vector
     * @param v The vector to divide
     * @param numberOfChunks The number of desires smaller vectors
     * @return The <numberOfChunks> smaller vectors
     */
    template<class T>
    [[nodiscard]] static vector<vector<T>> createChunks(vector<T> v, unsigned long numberOfChunks) {
        if (numberOfChunks > v.size()) {
            numberOfChunks = v.size();
        }

        unsigned long chunkSize = v.size() / numberOfChunks;
        vector<vector<T>> vectors(numberOfChunks);

        for (unsigned long i = 0; i < numberOfChunks - 1; i++) {
            unsigned long start = i * chunkSize;
            unsigned long end = (i + 1) * chunkSize - 1;

            vectors[i] = Utils::sliceVector(v, start, end);
        }

        unsigned long start = (numberOfChunks - 1) * chunkSize;
        unsigned long end = v.size() - 1;
        vectors[numberOfChunks - 1] = Utils::sliceVector(v, start, end);

        return vectors;
    }

    /**
     * Extract all the different symbols from a file
     * @param path The file path
     * @return The different symbols that are present in the file as a string
     */
    [[nodiscard]] static string extractSymbolsFromFile(const string &path);

    /**
     * Try to open a file from the file system
     * @param path The file path
     * @return An ifstream of the file
     */
    [[nodiscard]] static ifstream openFile(const string &path);
};
