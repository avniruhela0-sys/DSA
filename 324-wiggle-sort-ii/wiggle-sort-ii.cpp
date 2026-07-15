class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp= nums;
        int n = nums.size();
        int mid = (n + 1) / 2;
        int left=mid-1;
        int right=n-1;
        for(int i=0;i<n;i=i+2){
            nums[i]=temp[left--];
        }
        for(int i=1;i<n;i=i+2){
            nums[i]=temp[right--];
        }
    }
};