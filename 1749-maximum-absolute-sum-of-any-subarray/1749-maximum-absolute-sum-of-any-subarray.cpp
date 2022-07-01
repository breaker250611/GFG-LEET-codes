class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;
        int curr1 = 0;
        int mini = INT_MAX;
        
        for(int i = 0;i<nums.size();i++){
            curr +=nums[i];
            curr1 += nums[i];
            maxi = max(maxi,curr);
            if(curr<0) curr = 0;
            mini = min(curr1,mini);
            if(curr1>0) curr1 = 0;
            
        }
        
        // for(int i = 0;i<nums.size();i++){
        //     curr +=nums[i];
        //     mini = min(mini,curr);
        //     if(curr>0) curr = 0;
        // }
        return max(maxi,abs(mini));
    }
};