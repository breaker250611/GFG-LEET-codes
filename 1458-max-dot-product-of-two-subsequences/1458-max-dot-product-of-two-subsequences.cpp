class Solution {
public:
    vector<vector<int>>dp;
    int sol(vector<int>&nums1,vector<int>&nums2,int i ,int  j ){
        if(i>=nums1.size() or j>=nums2.size()) return -1e4;
        
        int &ans = dp[i][j];
        if(ans==INT_MIN){
            long long  peh = max(nums1[i]*nums2[j] , nums1[i]*nums2[j]+sol(nums1,nums2,i+1,j+1));
            long long  dus = sol(nums1,nums2,i+1,j);
            long long  tees = sol(nums1,nums2,i,j+1);
            ans = max({peh,dus,tees});
        }
        return ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return sol(nums1,nums2,0,0);
    }
};