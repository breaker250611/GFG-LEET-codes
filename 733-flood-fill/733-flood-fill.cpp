class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newcolor,int og,vector<vector<int>>&visited){
        int n = image.size();
        int m = image[0].size();
        
        if(sr>=n||sc>=m||sr<0||sc<0||image[sr][sc]!=og)return;
        else if(visited[sr][sc]==1) return;
        else{
        visited[sr][sc]=1;
            image[sr][sc]=newcolor;
            dfs(image,sr+1,sc,newcolor,og,visited);
            dfs(image,sr,sc+1,newcolor,og,visited);
            dfs(image,sr,sc-1,newcolor,og,visited);
            dfs(image,sr-1,sc,newcolor,og,visited);

        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
         dfs(image,sr,sc,newcolor,image[sr][sc],visited);
        return image;
    }
};