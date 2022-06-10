class Solution {
public:

    int tt(vector<int>& nums, int target) {
        
        int low = 0 , high = nums.size()-1;
        
        while (low <= high){
            int mid = (low + high)/2;
            
            if (nums[mid] == target)
                return mid;
                     
            if (nums[low] < nums[mid]){
                if (nums[low] <= target and target <= nums[mid]){
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
            else if(nums[high]>nums[mid]){
                  if (nums[mid] <= target and target <= nums[high]){
                    low = mid+1;
                }
                else
                    high = mid-1;
            }
            else{
                if(nums[low]==nums[mid]) low++;
                if(nums[high]==nums[mid]) high--;
            }
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int ans = tt(nums,target);
        if(ans==-1) return false;
        return true;
    }
};