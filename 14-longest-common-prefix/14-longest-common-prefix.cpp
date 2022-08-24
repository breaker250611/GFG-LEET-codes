class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans = strs[0];
        
        for(int j = 0;j<strs.size();j++){
            string temp = strs[j];
            string test = "";
            for(int i = 0; (i<temp.size() and i<ans.size());i++){
                if(temp[i]==ans[i]) test +=temp[i];
                else break;
            }
            ans = test;
        }
        return ans;
    }
};