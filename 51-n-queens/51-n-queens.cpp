class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vp;
        
        vector<bool>nd(n+n,false);
        vector<bool>rnd(n+n,false);
        vector<bool>col(n,false);
        string use = "";
        for(int i = 0;i<n;i++) use +='.';
        kuchkuch(n,vp,nd,rnd,col,0,{},use);
        return vp;
    }
    void kuchkuch(int n,vector<vector<string>>&vp,vector<bool>&nd,vector<bool>&rnd,vector<bool>&col,int i,vector<string>temp,string use){
        
        if(i==n){
            vp.push_back(temp);
            return;
        }
        
        temp.push_back(use);
        for(int j = 0;j<n;j++){
        if(nd[i+j]==false&&rnd[i-j+(n-1)]==false&&col[j]==false){
                        temp[i][j]='Q';
            nd[i+j]=true;
            rnd[i-j+(n-1)]=true;
            col[j]=true;
            kuchkuch(n,vp,nd,rnd,col,i+1,temp,use);
                        temp[i][j]='.';
            nd[i+j]=false;
            rnd[i-j+(n-1)]=false;
            col[j]=false;

        }
        }
        
    }
};