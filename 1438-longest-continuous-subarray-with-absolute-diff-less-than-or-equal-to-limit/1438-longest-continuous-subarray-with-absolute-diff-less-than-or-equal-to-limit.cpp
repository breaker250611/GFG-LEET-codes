class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        map<int,int>mp;
        
        
        int start = 0;
        int slow = 0;
        int ans = 1;
        for(slow = 0;slow<nums.size();slow++){
            mp[nums[slow]]++;
            int chota = mp.begin()->first;
            int bada = mp.rbegin()->first;
            
            while(bada-chota > k and start <slow){
                mp[nums[start]]--;
                if(mp[nums[start]]==0) mp.erase(nums[start]);
                start++;
                chota = mp.begin()->first;
                bada = mp.rbegin()->first;
            }
            if(bada-chota <=k) ans = max(ans,abs(start-slow)+1);
        }
        return ans;
    }
};