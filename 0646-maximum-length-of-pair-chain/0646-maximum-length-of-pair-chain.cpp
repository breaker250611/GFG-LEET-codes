class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        vector<int>vp(pairs.size(),1);
        int ans = 1;
        for(int i = 1;i<pairs.size();i++){
            for(int k = i-1;k>=0;k--){
                if(pairs[i][0]>pairs[k][1]){
                    int temp = vp[k]+1;
                    vp[i] = max(vp[i],temp);
                    
                    ans = max(vp[i],ans);
                }
            }
        }
        return ans;
        
    }
};