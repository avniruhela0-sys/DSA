#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    // Helper function to expand around the center and return the length of the
    // palindrome
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome found
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {

            int len1 = expandAroundCenter(s, i, i);

            int len2 = expandAroundCenter(s, i, i + 1);

            int currentMaxLen = max(len1, len2);

            // Update the global maximum and starting position if a longer
            // palindrome is found
            if (currentMaxLen > maxLength) {
                maxLength = currentMaxLen;
                start = i - (currentMaxLen - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};