class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        for (auto &x : nums)
            if (x <= 0 or x > n) x = n+2;
            
        for (int i = 0; i < n ; i++){
            int no = abs(nums[i]);
            if (no == 0 or no > n)
                continue;
            if (nums[no-1] > 0){
                nums[no-1] = -1 * nums[no-1];
            }
        }
        int ans = 0;
        for ( ; ans < n ; ans++){
            if (nums[ans] >= 0){
                return ans+1;
            }
        }
        return ans+1;
    }
};