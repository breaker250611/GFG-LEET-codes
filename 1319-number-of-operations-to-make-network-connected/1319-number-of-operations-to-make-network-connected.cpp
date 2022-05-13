class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1)
            return -1;
        
        vector<int> parent(n,-1);
        
        int count=1;
        for(int i=0;i<connections.size();i++)
        {
            uni(parent,connections[i][0],connections[i][1],count);
        }
        
        return n-count;
        
    }
    int findAbsParent(vector<int>& parent,int i)
    {
        while(parent[i]!=-1)
            i=parent[i];
        return i;
    }
    
    void uni(vector<int>& parent,int x,int y,int& count)
    {
        int parent1=findAbsParent(parent,x);
        int parent2=findAbsParent(parent,y);
        if(parent1!=parent2)
        {
            parent[parent1]=parent2;
            count++;
        }
    }
};