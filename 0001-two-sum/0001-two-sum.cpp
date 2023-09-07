class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp; // 1. value 2. index
        
        for(int i = 0;i<nums.size();i++){
            
            int num = nums[i];
            if(mp.find(target-num)!=mp.end()){
                return {mp[target-num],i};
            }
            mp[num] = i;
        }
        return {};
    }
};