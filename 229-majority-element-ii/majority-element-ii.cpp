class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int m=n/3;
        unordered_map<int,int> count;
        vector<int> result;
        for(int x: nums){
            count[x]++;
        }
        for(auto const&[val,freq]: count){
            if(freq>m){
                result.push_back(val);
            }
        }
        return result;
    }    
};