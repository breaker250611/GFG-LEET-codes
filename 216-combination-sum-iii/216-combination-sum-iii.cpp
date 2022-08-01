class Solution {
public:
    vector<vector<int>>ans;
    void call(int k,int n,int i , vector<int>&daal){
        if(n==0 and k==0){
            ans.push_back(daal);
            return;
        }
        if(n<=0 or k<=0) return;
        
        for(int j = i;j<=n;j++){
            if(n-j>=0 and j/10==0){
                daal.push_back(j);
                call(k-1,n-j,j+1,daal);
                daal.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int>daal;
        call(k,n,1,daal);
        return ans;
    }
};