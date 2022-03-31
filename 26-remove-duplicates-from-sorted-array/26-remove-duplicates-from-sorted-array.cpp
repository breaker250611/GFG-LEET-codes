class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(auto &x:nums){
            if(ans.size()!=0){
                if(ans[ans.size()-1]==x)continue;
                else{
                    ans.push_back(x);
                }
            }
            else{
                ans.push_back(x);
            }
        }
        nums = ans;
        return ans.size();
    }
};