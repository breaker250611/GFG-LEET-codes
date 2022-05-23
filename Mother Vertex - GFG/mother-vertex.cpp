// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	 void dfs( int node , vector<int>adj[] , vector<int>&vis , vector<int>&stack){
        
        vis[node] = true;
        for (auto x : adj[node]){
            if (!vis[x]){
                dfs(x , adj , vis , stack);
            }
        }
        stack.push_back(node);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	     vector<int> stack , vis(V , false); 
        
        for (int i = 0 ; i < V ; i++){
            if (!vis[i]){
                dfs( i ,adj , vis , stack);
            }
        }
        
        for (int i = 0 ; i<V ; i++){
            vis[i] = false;
        }
        int mother = stack.back();
        stack.clear();
        dfs(mother , adj , vis , stack);
        
        for (int i = 0 ; i<V ; i++){
            if (!vis[i])
              return -1;
        }
        return mother;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends