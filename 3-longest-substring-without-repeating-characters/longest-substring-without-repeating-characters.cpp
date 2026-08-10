#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character (initialized to -1)
        vector<int> charIndex(128, -1);
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If the character has been seen and is inside the current window,
            // shift the left pointer to the right of that character's last position.
            if (charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndex[currentChar] = right;
            
            // Calculate and update the maximum length of the substring without duplicates
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};