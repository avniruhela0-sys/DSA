class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // If string is all whitespace
        if (i == n) return 0;
        
        // Step 2: Check for sign (+ or -)
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        long long result = 0;
        
        // Step 3: Convert characters to digits and handle overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow/underflow before multiplying and adding
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return static_cast<int>(result * sign);
        
    }
};