class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int temp = ans[i/2]+i%2;
            ans.push_back(temp);
        }
        return ans;
    }
};