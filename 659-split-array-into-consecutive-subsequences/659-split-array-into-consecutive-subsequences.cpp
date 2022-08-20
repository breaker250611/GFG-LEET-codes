class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>available;
        map<int,int>required;
        
        for(auto &it:nums) available[it]++;
        
        for(int i = 0;i<nums.size();i++){
            int no = nums[i];
            if(required[no]>0){
                if(available[no]>0){
                    available[no]--;
                    required[no]--;
                    required[no+1]++;
                }
            }
            else if(available[no]>0){
                if(available[no+1]>0 and available[no+2]>0){
                    available[no]--;
                    available[no+1]--;
                    available[no+2]--;
                    required[no+3]++;
                }
                else return false;
            }
            
        }
        return true;
    }
};