#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stores indices of the bars
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // If we are past the end of the array, treat the height as 0 
            // to flush out all remaining bars in the stack.
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // While stack is not empty and current bar is shorter than the stack's top bar
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()]; // The height of the rectangle
                st.pop();
                
                // Calculate width
                // If stack is empty, it means this bar was the shortest from index 0 to i-1
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = max(maxArea, height * width);
            }
            
            // Push the current index into the stack
            st.push(i);
        }
        
        return maxArea;
    }
};