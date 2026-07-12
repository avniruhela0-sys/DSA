class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);   // extra array to count occurrences
        vector<int> ans;

        // Step 1: count how many times each number appears
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        // Step 2: check which numbers appeared more than once
        for (int num = 1; num <= n; num++) {
            if (count[num] > 1) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};