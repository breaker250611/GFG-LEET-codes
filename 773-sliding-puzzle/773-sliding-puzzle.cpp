/*
Used bfs , after changing the board in string to make it easier for visited array 
jaha jaha ja sakta hai mera wo zero wo sab mai ek array mai store karlunga ..
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        queue<string>qu;
        string init = "";
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                init = init + to_string(board[i][j]);
            }
        }
        qu.push(init);
        set<string>st;
        st.insert(init);
        int level = 0;
        vector<vector<int>>jana = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
        
        while(qu.size()){
            int sz = qu.size();
            while(sz--){
                string str = qu.front();
                qu.pop();
                if(str==target) return level;
                int idx = -1;
                for(int i =0;i<str.size();i++){
                    if(str[i]=='0'){
                        idx = i;
                        break;
                    }
                }
                vector<int> &temp = jana[idx];
                for(int i = 0;i<temp.size();i++){
                    string naya = str;
                    char ch = naya[idx];
                    naya[idx] = naya[temp[i]];
                    naya[temp[i]] = ch;
                    // cout<<"str = "<< str<<endl;
                    // cout<<"naya = "<<naya<<endl;
                    if(st.find(naya)!= st.end()) continue;
                    qu.push(naya);
                    st.insert(naya);
                }
            }
            level++;
        }
        return -1;
    }
};