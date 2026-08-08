class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the element at mid is greater than the element at right,
            // it means the minimum element must be in the right half.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, the minimum element is at mid or in the left half.
            else {
                right = mid;
            }
        }
        
        // When left meets right, we have found the minimum element
        return nums[left];
    }
};