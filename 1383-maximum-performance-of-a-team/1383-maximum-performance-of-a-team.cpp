const  long long int mod = 1e9 + 7;
class Solution {
public:
    // sort kardo efficiency se taaki har baar iteration mai choti waali mil jae
    // speed ko pq mai daalte jao and k size se jyada hohne pe nikalte jao
    // pq min heap lenge sabse upar sabse chota
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>vp;
        for(int i = 0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        sort(vp.rbegin(),vp.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int sum =0;
        long long int ans = 0;
        
        for(int i = 0;i<n;i++){
            long long int eff = vp[i].first;
            int s = vp[i].second;
            
            sum += s;
            pq.push(s);
            while(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            long long int hain = (sum*eff);
            ans = max(ans,hain);
        }
        return ans%mod;
    }
};