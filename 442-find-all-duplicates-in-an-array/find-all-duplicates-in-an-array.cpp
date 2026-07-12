class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n+1,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(int num=1;num<=n;num++){
            if(count[num]>1){
                ans.push_back(num);
            }
        }
        return ans;
    }
};