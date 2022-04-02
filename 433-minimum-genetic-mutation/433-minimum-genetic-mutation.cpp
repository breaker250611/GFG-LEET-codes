class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_map<string,int> m;
        for(auto p:bank)
            m[p]++;
        
        if(m.find(end)==m.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string temp=q.front();
                q.pop();
                if(temp==end)
                    return ans;
                
                for(int j=0;j<8;j++) 
                {
                    char c=temp[j];
                    for(auto p:"AGCT") 
                    {
                        if(p==c)
                            continue;
                        temp[j]=p;
                        if(m.find(temp)!=m.end())
                            q.push(temp);
                    }
                    temp[j] = c;
                }
            }
            ans++;
        }
        return -1;
    }
};