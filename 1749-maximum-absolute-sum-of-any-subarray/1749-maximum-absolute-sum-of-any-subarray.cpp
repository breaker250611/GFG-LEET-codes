class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            curr +=nums[i];
            maxi = max(maxi,curr);
            if(curr<0) curr = 0;
        }
         curr = 0;
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            curr +=nums[i];
            mini = min(mini,curr);
            if(curr>0) curr = 0;
        }
        return max(maxi,abs(mini));
    }
};