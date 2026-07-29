#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result = "";
        
        // Extract words one by one
        while (ss >> word) {
            // If result is empty, it's the first word we are adding (in reverse order)
            // Otherwise, put the new word BEFORE the old result with a space in between
            if (result == "") {
                result = word;
            } else {
                result = word + " " + result;
            }
        }
        
        return result;
    }
};