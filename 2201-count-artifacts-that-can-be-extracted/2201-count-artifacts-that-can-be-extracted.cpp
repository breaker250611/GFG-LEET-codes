class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int,int>,bool>mp;
        for(int i = 0;i<dig.size();i++){
            int x = dig[i][0];
            int y = dig[i][1];
            mp[{x,y}] = true;
        }
        int count = 0;
        
        for(int i = 0;i<artifacts.size();i++){
            int a  = artifacts[i][0];
            int b  = artifacts[i][1];
            int x1  = artifacts[i][2];
            int y1  = artifacts[i][3];
            bool flag= true;
            for(int x = a ;x<=x1;x++){
                for(int y =b;y<=y1;y++){
                    if(mp[{x,y}] == false){
                        flag= false;
                    }
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};