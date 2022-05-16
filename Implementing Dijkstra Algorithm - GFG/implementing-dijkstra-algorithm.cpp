// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    vector<int> distance(V,1000000000);
    vector<int> parent (V,-1);
     
     distance[S] = 0;
     using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,S});
    while(!q.empty()){
        int prnt = q.top().second;
        int abhidistance = q.top().first;
        q.pop();
        if(abhidistance > distance[prnt]){
            continue;
        }
        for(auto edge :adj[prnt]){
            int newdist = edge[1];
            int to = edge[0];
            if(distance[prnt] + newdist <distance[to]){
                distance[to] = distance[prnt] + newdist;
                parent[to] = prnt;
                q.push({distance[to],to});
            }
        }
    }
    return distance;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends