class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};
        if(nums.size()==0)return ans;
        int lo = 0,hi=nums.size()-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                ans[0] = mid;
                hi = mid-1;
            }
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        
        
        if(ans[0]==-1) return ans;
        
        
        lo = 0,hi = nums.size()-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
             if(nums[mid] == target){
                ans[1] = mid;
                lo = mid+1;
            }
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
            
        }
            // cout<<"checl"<<endl;
        return ans;
    }
};