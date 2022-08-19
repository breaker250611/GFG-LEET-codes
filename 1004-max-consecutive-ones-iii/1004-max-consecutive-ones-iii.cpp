class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count0 = 0;
        
        int lo = 0;
        int ans = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int temp = nums[i];
            if(temp==0){
                count0++;
                while(count0>k and lo<=nums.size()){
                    if(nums[lo]==0)count0--;
                    lo++;
                }
            }
            
            ans = max(ans,i-lo+1);
            
        }
        return ans;
    }
};