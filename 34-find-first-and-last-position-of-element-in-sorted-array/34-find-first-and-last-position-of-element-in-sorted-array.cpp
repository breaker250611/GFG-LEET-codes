class Solution {
public:
    
    int binarysearch_first(vector<int> &nums , int low , int high , int target){
        
        int ans = -1;
        while (low <= high){
            
            int mid = (low + high)/2;
            
            if (nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if (nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return ans;  
    }
    
    int binarysearch_second(vector<int> &nums , int low , int high , int target){
        
        int ans = -1;
        while (low <= high){
            
            int mid = (low + high)/2;
            
            if (nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return ans;  
      
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
     
        // 0 for front ... //
        int first = binarysearch_first(nums , 0 , nums.size()-1 , target);
        // 1 for back  ... //
        int second = binarysearch_second(nums , 0 , nums.size()-1 , target);
        return {first , second};
    }
};