class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        
        while(low<=high){
            int mid  = (low+high)/2;
            
            if(nums[mid]==target){
                return true;
            }
            
            if(nums[mid]>nums[low]){
                if(target>=nums[low] and target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            else if(nums[mid]<nums[high]){
                if(target>nums[mid] and target<=nums[high]){
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
            else {
                if(nums[mid]==nums[low])low++;
                else if(nums[mid]==nums[high])high--;
            }
        }
        
        return false;
    }
};