class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            int leftsum=prefix[i];
            int rightsum=prefix[n]-leftsum-nums[i];
            if(leftsum==rightsum){
                return i;
            }
        }
        return -1;
    }
};