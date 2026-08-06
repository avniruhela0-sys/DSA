class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // If we find the target, or if we find a number 
            // that is greater than the target, 'i' is our answer!
            if (nums[i] >= target) {
                return i;
            }
        }
        // If we reach here, it means the target is larger than 
        // all elements in the array, so it goes at the very end.
        return nums.size();
    }
};