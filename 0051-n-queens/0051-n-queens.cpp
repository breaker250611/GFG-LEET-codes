class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
        vector<bool>col(n,false);
        vector<bool>dia(n+n,false);
        vector<bool>odia(n+n,false);
        string use = "";
        for(int i = 0;i<n;i++) use +=".";
        
        fun(n,ans,col,dia,odia,0,{},use);
        return ans;
        
    }
    
    
    void fun(int n,vector<vector<string>>&ans,vector<bool>&col,vector<bool>&dia,vector<bool>&odia,int i,vector<string>temp,string &use){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        
        temp.push_back(use);
        
        for(int j = 0;j<n;j++){
            
            if(col[j]==false and dia[i+j]==false and odia[i-j+n-1]==false){
                temp[i][j] = 'Q';
                col[j] = true;
                dia[i+j]= true;
                odia[i-j+n-1] = true;
                fun(n,ans,col,dia,odia,i+1,temp,use);
                temp[i][j] = '.';
                col[j] = false;
                dia[i+j] = false;
                odia[i-j+n-1] = false;
            }
            
            
        }
    }
};