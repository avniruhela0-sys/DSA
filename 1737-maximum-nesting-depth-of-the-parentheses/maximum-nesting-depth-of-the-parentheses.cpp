class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepthCount = 0;
        
        for (char c : s) {
            if (c == '(') {
                currentDepth++;
                // Update the maximum depth encountered so far
                maxDepthCount = max(maxDepthCount, currentDepth);
            } else if (c == ')') {
                currentDepth--;
            }
        }
        
        return maxDepthCount;
        
    }
};