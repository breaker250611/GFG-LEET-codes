class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        vector<int>vc(temp.size());
        
        for(int i = temp.size()-1;i>=0;i--){
            
            while(st.size()>0 and temp[st.top()]<=temp[i]) st.pop();
            vc[i] = 0;
            if(st.size()){
                int temp = abs(st.top()-i);
                vc[i] = temp;
            }
            st.push(i);
        }
        return vc;
    }
};