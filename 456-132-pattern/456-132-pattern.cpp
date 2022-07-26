class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>arr;
        
        for(int i = 0;i<nums.size();i++){
            if(i==0){
                arr.push_back(nums[i]);
            }
            else{
                if(nums[i]<arr.back()){
                    arr.push_back(nums[i]);
                }
                else arr.push_back(arr.back());
            }
        }
                int next = INT_MIN;

        stack<int>st;
        // potential 2 ko stack mai daalo
        st.push(nums.back());
        for(int i = nums.size()-2;i>=1;i--){
            
while (!st.empty() && st.top() < nums[i]) {
                next = max(next, st.top());
                st.pop();
            }
            
            if (next < nums[i] && arr[i-1] < next) {
                return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};