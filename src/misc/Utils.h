//
//
// Created by owen on 19.05.22.
//

#pragma one

#include <string>
#include <fstream>

using namespace std;

class Utils {
public:
    void static readFile(const string &path, void (const string &, unsigned int));

    /**
     * Get the alphabet as a string representation
     * @param max The max number of letters
     * @return The alphabet letters
     */
    static string getAlphabet(int max = 26);

    /**
     * Get the index of the letter in the alphabet (begins at 0)
     * A => 0
     * B => 1
     * C => 2
     * ...
     * @param letter
     * @return The letter index, it begins at index 0
     */
    static int getIndexInAlphabet(char letter);

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
};
