class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int x : nums) {
            // If count is 0, we pick a new candidate
            if (count == 0) {
                candidate = x;
            }
            
            // If current number matches, increment; otherwise, decrement
            if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};