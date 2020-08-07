/*
Author: chankruze (chankruze@geekofia.in)
Created: Fri Aug 07 2020 04:20:33 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int noOfOccurrenceEach(string* str_in) {
    std::map<char, int> count;
    string str = *str_in;
    int l = str.length();

    for (int i = 0; i < l; i++) {
        if (str[i] != ' ') {
            count[str[i]]++;
        }
    }

    for (const auto kvp : count) {
        std::cout << kvp.first << " occurs " << kvp.second << " times\n";
    }
    return 0;
}

bool isVowel(char ch) {
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int noOfPairVowels(string* str) {
    string new_str = *str, word = "";
    int count = 0;
    std::map<string, int> data;

    // loop thru entire string sentence
    for (int i = 0; i < new_str.length(); ++i) {
        char ch = new_str.at(i);

        // extracting each word
        if (ch != ' ') {
            word = word + ch;
        } else {
            // check how main vowel pairs in each word
            int cnt = 0;
            for (int i = 0; i < word.length(); ++i) {
                // If current character and the
                // character after it are both vowels
                if (isVowel(word[i]) && isVowel(word[i + 1]))
                    cnt++;
            }
            data[word]++;
            word = "";
        }
    }

    // int cnt = 0;
    // for (int i = 0; i < str.length() - 1; ++i) {
    //     // If current character and the
    //     // character after it are both vowels
    //     if (isVowel(str[i]) && isVowel(str[i + 1]))
    //         cnt++;
    // }

    for (const auto kvp : data) {
        std::cout << kvp.first << " has " << kvp.second << " pair vowels\n";
    }

    return 0;
}

bool checkPalin(string word) {
    int n = word.length();
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0; i < n; i++, n--) {
        if (word.at(i) != word.at(n - 1)) {
            return false;
        }
    }

    return true;
}

int noOfPalindromeWord(string* str) {
    string new_str = *str, word = "";
    int count = 0;

    for (int i = 0; i < new_str.length(); ++i) {
        char ch = new_str.at(i);

        cout << ch;

        // extracting each word
        if (ch != ' ') {
            word = word + ch;
        } else {
            if (checkPalin(word))
                count++;
            word = "";
        }
    }

    return count;
}

int main(int argc, char const* argv[]) {
    cout << "Input any string:" << endl;
    string line;
    getline(cin, line);
    system("clear");

    // number of occurrence of each word
    //cout << "1. Number of occurrence of each character of each word:\n" << endl;
    //noOfOccurrenceEach(&line);
    // number of pair vowels in each word
    //cout << "\n2. Number of pair vowels in each word:\n" << endl;
    //noOfPairVowels(&line);
    // number of palindrome word
    cout << "\n3. Number of palindrome words: " << noOfPalindromeWord(&line) << endl;

    return 0;
}
