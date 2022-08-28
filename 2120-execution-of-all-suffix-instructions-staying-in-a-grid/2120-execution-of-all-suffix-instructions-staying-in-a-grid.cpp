class Solution {
public:
    int n ;
    int call(int x,int y,string &str,int i){
        if(x<0 or y<0 or x>=n or y>=n)return -1;
        if(i>=str.size())return 0;
        char ch = str[i];
        if(ch=='R'){
            return 1+call(x,y+1,str,i+1);
        }
        else if(ch=='L'){
            return 1+call(x,y-1,str,i+1);
            
        }
        else if(ch=='U'){
            
            return 1+call(x-1,y,str,i+1);
        }
        else if(ch=='D'){
            return 1+call(x+1,y,str,i+1);
            
        }
        return 0;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string &s) {
        this-> n = n;
        vector<int>ans;
            int x = startPos[0];
            int y = startPos[1];
        for(int i = 0;i<s.size();i++){
            // string temp = s.substr(i);
            int cnt = call(x,y,s,i);
            ans.push_back(cnt);
        }
        return ans;
    }
};