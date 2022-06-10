class Solution {
public:
    bool check(vector<int> &arr , int m){
        int count = 0;
        for (int i = 0 ; i < arr.size() ; i++){
            arr[i] <= m ? count++ : count;
        }
        return count > m;
    }
    
    int findDuplicate(vector<int>& nums) {
        
        int low = 1 , high = nums.size()-1;
        int ans = -1;
        while (low <= high){
            
            int mid = (low+high)/2;
            bool ok = check(nums , mid);
            
            if (ok){
                ans = mid;
                high = mid-1;
            }
            else {
               low = mid+1;   
            }
        }
        return ans;
    }
};