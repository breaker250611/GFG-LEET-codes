class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int l) {
        vector<int>ans;
        vector<long long int>presum;
        long long int sum = 0;
        presum.push_back(sum);
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            presum.push_back(sum);
        }
        
        // for(auto &it:presum)
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            
            if(i<l){
                ans.push_back(-1);
            }
            else{
                if(i+l<nums.size()){
                    long long int daalna = (0LL + presum[i+l+1]-presum[k]);
                    daalna = daalna/(2*l+1);
                    k++;
                    ans.push_back(daalna);
                }
                else{
                    ans.push_back(-1);
                }
            }
            
            
        }
        return ans;
    }
};