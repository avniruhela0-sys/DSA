#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q; // Stores indices of elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove indices that are out of the current window left-boundary
            if (!q.empty() && q.front() < i - k + 1) {
                q.pop_front();
            }
            
            // 2. Remove smaller elements from the back as they are useless
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            
            // 3. Add the current element's index to the back
            q.push_back(i);
            
            // 4. Once we reach the size of k, record the maximum for this window
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        
        return res;
    }
};