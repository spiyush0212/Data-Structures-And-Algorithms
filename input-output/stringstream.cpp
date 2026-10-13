/*
========================================
          STRINGSTREAM
========================================

1. WHAT IS STRINGSTREAM?
------------------------
- stringstream treats a string like an input/output stream.
- It allows us to read words from a string using >>.
- Header: #include <sstream>
- Namespace: std


2. HOW IT WORKS INTERNALLY
--------------------------
- Stores the input string in an internal buffer.
- Maintains a read position to track the next character.
- The >> operator extracts data from the stream.
- By default, >> skips leading whitespace and reads until the next whitespace character.

string s = "Hello World";
stringstream ss(s);

- Initializes a stream with string s.
- Stores data in an internal buffer.


3. EXAMPLE
----------
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    stringstream ss("Hello World");
    string word;

    // Method 1:
    while (ss >> word)
        cout << word << " "; // Print it word by word

    // Method 2:
    ss >> word;  // word = "Hello"
    ss >> word;  // word = "World"
    ss >> word;  // Fails: no more words

    return 0;
}

/*
4. WHITESPACE HANDLING
----------------------
- Skips leading spaces.
- Handles consecutive spaces.
- Skips trailing whitespace when searching for the next word.
- Whitespace includes spaces, tabs, and newlines.


5. APPLICATION: LENGTH OF LAST WORD
-----------------------------------
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int result = 0;
        string word;

        while (ss >> word)
            result = word.size();

        return result;
    }
};

/*

6. COMPLEXITY
-------------
- Construction: O(N) time, typically.
- Total extraction: O(N) time.
- Auxiliary space: O(N) in the worst case.
  The stream's internal storage and extracted word can require space proportional to the input.


7. KEY TAKEAWAY
---------------
stringstream ss(s);
    Creates a stream from string s.

ss >> word;
    Extracts the next whitespace-separated word.

while (ss >> word)
    Repeats until extraction fails.

========================================
*/