class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = nums[0];
        
        int lo = 0;int hi = nums.size()-1;
        
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(nums[mid]>nums[mid+1]) hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};