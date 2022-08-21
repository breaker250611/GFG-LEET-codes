class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int maxi = INT_MIN;
        int zerocount = 0;
        int produc = 1;
        int ind = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0)zerocount++,ind = i;
            else produc *=nums[i],maxi  =max(produc,maxi);
        }
        if(zerocount>=2){
             vector<int>vp(nums.size(),0);
            return vp;
        }
        else if(zerocount ==1){
            vector<int>vp(nums.size(),0);
            vp[ind]=produc;
            return vp;
        }
        else{
            for(int i = 0;i<nums.size();i++){
                nums[i] = produc/nums[i];
            }
            return nums;
        }
    }
};