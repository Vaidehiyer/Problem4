/**
 * @file SpellChecker.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief This program reads a word and checks if it is spelled correctly.
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "DoublyLinkedBag.h"     // USe the Doubly linked bag we created in Task 1
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

/**
 * @brief Helper fucntion to lowercase a string
 * 
 * @param str : String
 */
void toLowerCase(string &str)
{
    for (char &c : str)
    {
        c = tolower(c);       // USe C++ library function to lower case
    }
}

/**
 * @brief Creates a DoublyLinkedBag that acts as the dictionary 
 * Containing all correctly-spelled words.
 * 
 * @param dictionary : DLB
 * @param filename : Name of the file containing all correctly spelled words
 */
void loadDictionary(DoublyLinkedBag<string> &dictionary, const string &filename)
{

    // Open the file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open dictionary file: " << filename << endl;
        exit(1);
    }

    // Read each word in file and add it to the bag
    string word;
    while (file >> word)
    {
        toLowerCase(word);
        dictionary.add(word);
    }
    file.close();
}

/**
 * @brief Spell checker function
 * 
 * @param dictionary : Dictionary
 * @param filename : Name of the file to check
 */
void checkSpelling(DoublyLinkedBag<string> &dictionary, const string &filename)
{
    // Open the file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open file to check: " << filename << endl;
        exit(1);
    }

    string word;      // to store each word
    bool firstIncorrectWord = true;  // to check if there exists any incorrect words

    while (file >> word)
    {
        toLowerCase(word);

        // If dictionary does not contain the word, then it is misspelled!
        if (!dictionary.contains(word))
        {
            if (firstIncorrectWord)
            {
                cout << "The following words in the file \"" << filename << "\" are not spelled correctly:" << endl;
                firstIncorrectWord = false;
            }
            cout << word << endl;
        }
    }

    // No misspelled words in the file
    if (firstIncorrectWord)
    {
        cout << "All words in the file \"" << filename << "\" are spelled correctly." << endl;
    }

    file.close();
}

// Tester
int main()
{
    DoublyLinkedBag<string> dictionary;
    string dictionaryFilename = "words.txt";
    string filenameToCheck;

    loadDictionary(dictionary, dictionaryFilename);

    cout << "Enter the name of the file that contains words to check:" << endl;
    cin >> filenameToCheck;

    checkSpelling(dictionary, filenameToCheck);

    cout << "Thanks for using the spell checker system." << endl;

    return 0;
}
