class TreeAncestor {
public:
    // int sz = 0;
    // vector<int> ancs;
    vector<vector<int>>dp;
    void call(int n, vector<int>&parent){
        int height =  16;
        dp.resize(16,vector<int>(n,0));
        
        for(int i = 0;i<n;i++){
            dp[0][i] = parent[i];
        }
        
        // 2^15 ancestor tak bharenge .
        
        for(int i = 1;i<16;i++){
            for(int node = 0;node<n;node++){
                int parent = dp[i-1][node];
                if(parent != -1){
                    dp[i][node] = dp[i-1][parent];
                }
                else {
                    dp[i][node] = -1;
                }
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        // sz = n;
        // ancs = parent;
        call(n,parent);
        // cout<<"h";
        
    
    }
    
    
    int getKthAncestor(int node, int k) {
        
        cout<<node<<" "<<k<<endl;
        
        for(int i = 0;i<16 and node != -1;i++){
            
            if((k & (1<<i))>0){
                node = dp[i][node];
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */