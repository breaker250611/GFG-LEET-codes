class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            
          if(nums[i]<=threshold){
            if(cnt==0){
                if(nums[i]%2==0){
                    cnt++;
                }
                
                ans  = max(ans,cnt);
            }
            else {
                    if(nums[i-1]%2 != nums[i]%2){
                        cnt++;
                    }
                else{
                    cnt = 0;
                }
                
                ans = max(ans,cnt);
            }
               ans = max(ans,cnt);
              if(cnt==0){
                if(nums[i]%2==0){
                    cnt++;
                }
                
                ans  = max(ans,cnt);
            }               

          }
            else  cnt = 0;
              ans = max(ans,cnt);
            
            
        }
        return ans;
    }
};