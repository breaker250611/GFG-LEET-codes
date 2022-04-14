class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1 ; i<nums.size() ; i++){
            if (temp.back() < nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(temp.begin() , temp.end() , nums[i])-temp.begin();
                temp[it] = nums[i];
            }
        }
       if(temp.size()>=3) return true;
        return false;
        
    }
};