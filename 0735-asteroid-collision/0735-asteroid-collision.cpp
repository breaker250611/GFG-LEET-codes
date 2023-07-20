class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int>st;
        // st.push(asteroids[0]);
        
        for(int i = 0;i<asteroids.size();i++){
            int val = asteroids[i];
            bool flag = true;
            
            while(st.size()>0 and st.top()>0 and val<0){
                
                int temp = st.top();
                st.pop();
                
                int diff = temp+val;
                if(diff==0){
                    flag = false;
                    break;
                }
                if(diff>0){
                    flag = false;
                    st.push(temp);
                    break;
                }
                
            }
           
                if(flag)st.push(val);
           
        }
        vector<int>ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};