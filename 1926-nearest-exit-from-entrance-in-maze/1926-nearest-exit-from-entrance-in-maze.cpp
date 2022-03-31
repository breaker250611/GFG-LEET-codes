class Solution {
public:
    vector<int> r={0,0,-1,1};
    vector<int> c={-1,1,0,0};
    int nearestExit(vector<vector<char>>& ma, vector<int>& e) {
        int n=ma.size(),m=ma[0].size(),res=0;
        int s1=e[0],s2=e[1];
        queue<pair<int,int>> q;
        ma[s1][s2]='+';
        q.push({s1,s2});
        while(!q.empty())
        {
            int s=q.size();
            res++;
            for(int k=0;k<s;k++)
            {
                auto j=q.front();
                for(int p=0;p<4;p++)
                {
                    int p1=j.first+r[p],p2=j.second+c[p];
                    if(p1<0||p2<0||p1>=n||p2>=m||ma[p1][p2]=='+')
                        continue;
                    if(p1==0||p2==0||p1==n-1||p2==m-1)
                        return(res);
                    ma[p1][p2]='+';
                    q.push({p1,p2});
                }
                q.pop();
            }
        }
        return(-1);
    }
};