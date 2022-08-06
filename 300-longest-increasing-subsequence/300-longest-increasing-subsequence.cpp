class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr;
        
        for(auto &it:nums){
            auto ind = lower_bound(arr.begin(),arr.end(),it);
            
            if(ind==arr.end()) arr.push_back(it);
            else{
                arr[ind-arr.begin()] = it;
            }
        }
        return arr.size();
    }
};