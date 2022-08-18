class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       map<int,int>st;
        int lo = 0;
        int maxi = 1;
        for(int i = 0;i<nums.size();i++ ){
            st[nums[i]]++;

            int diff = abs(st.begin()->first -st.rbegin()->first );
            
                while(diff>limit and st.size()){
                        st[nums[lo]]--;
                    if(st[nums[lo]]==0)st.erase(nums[lo]);
                    diff =abs(st.begin()->first -st.rbegin()->first );
                    lo++;
                }
            maxi = max(maxi,i-lo+1);
                
            
        }
        return maxi;
    }
};