#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to find the first (leftmost) occurrence of the target
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                first = mid;       // Record position
                right = mid - 1;   // Search further left for the first occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }
    
    // Helper function to find the last (rightmost) occurrence of the target
    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                last = mid;        // Record position
                left = mid + 1;    // Search further right for the last occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex = findFirst(nums, target);
        
        // If the target is not found at all, return [-1, -1] early
        if (firstIndex == -1) {
            return {-1, -1};
        }
        
        int lastIndex = findLast(nums, target);
        
        return {firstIndex, lastIndex};
    }
};