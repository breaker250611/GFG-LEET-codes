class Solution {
public:
     int ok(vector<int> &a){
        vector<int> prev_small(a.size() , -1);
        vector<int> next_small(a.size() , a.size());
        
        stack<int> st , temp;
        for (int i = a.size()-1 ; i >= 0 ; i--){
            while (!st.empty() and a[st.top()] >= a[i]){
                st.pop();
            }
            if (!st.empty())
            next_small[i] = st.top();     
            st.push(i);
        }
        
        swap(st , temp);
        
        for (int i = 0 ; i < a.size() ; i++){
            
            while (!st.empty() and a[st.top()] >= a[i]){
                st.pop();
            }
            if (!st.empty())
                prev_small[i] = st.top();
            st.push(i);
        }
        int mx = 0;
        for (int i = 0 ; i < a.size() ; i++){
            mx = max(mx  , a[i]*(next_small[i]-prev_small[i]-1));
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int ans = 0;
        vector<int>a(m,0);
        for (int i = 0 ; i < n ; i++){
            for (int j = 0;  j < m ; j++){
                if (matrix[i][j] == '1'){
                a[j] += (matrix[i][j]-'0');
                }
                else {
                    a[j] = 0;
                }
            }
            ans = max(ans , ok(a));
        }
        
        return ans;
    }
};