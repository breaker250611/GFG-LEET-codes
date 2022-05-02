class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        for(auto &it:nums){
            if(it%2==0) even.push_back(it);
            else odd.push_back(it);
        }
        for(int i = 0;i<odd.size();i++){
            even.push_back(odd[i]);
        }
        return even;
    }
};