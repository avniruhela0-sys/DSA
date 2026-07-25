class Solution {
public:
    string makeFancyString(string s) {
        string result= "";
        for(int i=0;i<s.length();i++){
            int n= result.length();
            if(n>=2 && result[n-1]==s[i] && result[n-2]==s[i] ){
                continue;
            }

            result.push_back(s[i]);
        }
        return result;
    }
};