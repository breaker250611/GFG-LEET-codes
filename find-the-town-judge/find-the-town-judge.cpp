class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>mp;
        for(int i=1;i<=n;i++)mp[i]=0;
        for(int i=0;i<trust.size();i++){
            int people = trust[i][0];
            int kara = trust[i][1];
            mp[people]--;
            mp[kara]++;
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==n-1) return it->first;
        }
        return -1;
    }
};