class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxprod = nums[0];
        int minprod = nums[0];
        int answer = nums[0];

        for(int i = 1; i < n; i++) {
            int oldmax = maxprod;
            int oldmin = minprod;

            maxprod = max({nums[i], nums[i] * oldmax, nums[i] * oldmin});
            minprod = min({nums[i], nums[i] * oldmax, nums[i] * oldmin});

            answer = max(answer, maxprod);
        }

        return answer;
    }
};