class NumArray {
public:

    // prefix is a class variable
    vector<int> prefix;

    // Constructor
    NumArray(vector<int>& nums) {

        int n = nums.size();

        // Create prefix array of size n + 1
        prefix.resize(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    // Return sum from left to right
    int sumRange(int left, int right) {

        return prefix[right + 1] - prefix[left];
    }
};