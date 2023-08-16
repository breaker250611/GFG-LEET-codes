class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==1 and k ==1) return nums;
     vector<int>ans;
     deque<int>dq;
        // dq.push_back(0);
        for(int i = 0;i<nums.size();i++){
            
            while(dq.empty()==false and i-dq.front()>=k){
                dq.pop_front();
            }
            
            while(dq.empty()==false and nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            // while(dq.empty())
            dq.push_back(i);
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    
    }
};