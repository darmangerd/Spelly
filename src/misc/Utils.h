//
//
// Created by owen on 19.05.22.
//

#pragma one

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
        long count = 0;
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
        long count = 0;
        while (file.get(c)) {
            f(c, count);
            count++;
        }

        file.close();
    }

    /**
     * Init an array of type T with a default value for each element
     * @tparam T The array type
     * @param default_value The default value
     * @param size The array size
     * @return The array of type T with the specified size filled with the default value
     */
    template<class T>
    static T *initArray(T default_value, unsigned int size) {
        T *arr = new T[size];

        for (int i = 0; i < size; i++) {
            arr[i] = default_value;
        }

        return arr;
    }

    /**
     * Swap two variables of type T
     * @tparam T The type of the variables
     * @param a The first variable to swap
     * @param b The second variable to swap
     */
    template<class T>
    static void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template<class T>
    static vector<T> createVectorSlice(vector<T> v, unsigned int start, unsigned int end) {
        vector<T> vSlice(end - start);
        copy(v.begin() + start, v.begin() + end, vSlice.begin());

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
    static vector<T> *createChunks(vector<T> v, unsigned int numberOfChunks) {
        unsigned int chunkSize = v.size() / numberOfChunks;
        auto vectors = new vector<T>[numberOfChunks];

        for (unsigned int i = 0; i < numberOfChunks - 1; i++) {
            unsigned int start = i * chunkSize;
            unsigned int end = (i + 1) * chunkSize;

            vectors[i] = Utils::createVectorSlice(v, start, end);
        }

        unsigned int start = (numberOfChunks - 1) * chunkSize;
        unsigned int end = v.size();
        vectors[numberOfChunks - 1] = Utils::createVectorSlice(v, start, end);

        return vectors;
    }

    /**
     * Extract all the different symbols from a file
     * @param path The file path
     * @return The different symbols that are present in the file as a string
     */
    static string extractSymbolsFromFile(const string &path);

    /**
     * Get the alphabet as a string representation
     * @param max The max number of letters
     * @return The alphabet letters
     */
    static array<char, 26> getAlphabet(int max = 26);

    /**
     * Get the index of the letter in the alphabet (begins at 0)
     * A => 0
     * B => 1
     * C => 2
     * ...
     * @param letter The letter to findCandidates
     * @return The letter index, it begins at index 0
     */
    static int getIndexInAlphabet(char letter);

    /**
     * Get the index of the letter in a custom alphabet (begins at 0)
     * @param letter The letter to findCandidates
     * @param alphabet The custom alphabet as a string
     * @return The letter index, it begins at index 0
     */
    static int getIndexInAlphabet(char letter, string alphabet);

    /**
     * Return the letter (char) that is positioned at a specified index in the alphabet
     * 0 => 'A'
     * 1 => 'B'
     * 2 => 'C'
     * ...
     * @param letterIndex The index of the letter in the alphabet
     * @return The letter (chat) that is positioned at the specified index
     */
    static char getLetterFromAlphabetIndex(int letterIndex);

    /**
     * Try to open a file from the file system
     * @param path The file path
     * @return An ifstream of the file
     */
    static ifstream openFile(const string &path);
};
