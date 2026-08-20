class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=prefix[j+1]-prefix[i];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
            
            
    }
};