class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int> ans;
        
        stack<int>st;
        // st.push(-1);
        for(int i = nums2.size()-1;i>=0;i--){
            
            while(st.size()>0 and st.top()<nums2[i]){
        cout<<"he";
                st.pop();
            }
            int mila = -1;
            if(st.size()){
                mila = st.top();
            }
            mp[nums2[i]] = mila;
            st.push(nums2[i]);
        }
        for(int i = 0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
        
    }
};