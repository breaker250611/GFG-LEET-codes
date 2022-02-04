class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n,0);
        vector<int>mini(n,0);
        maxi[0]=(nums[0]>0)?nums[0]:1;
        mini[0] = (nums[0]<0)?nums[0]:1;
        int ans = nums[0];
        for(int i=1;i<n;i++){
            maxi[i] = max({nums[i]*maxi[i-1],nums[i]*mini[i-1],nums[i]});
            mini[i] = min({nums[i]*maxi[i-1],nums[i]*mini[i-1],nums[i]});
            if(maxi[i]>ans) ans = maxi[i];

        }
        return ans;
    }
};