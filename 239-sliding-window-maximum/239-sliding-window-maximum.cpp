class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
         priority_queue<pair<int,int>>pq;
 int n = arr.size();
    vector<int>vp(n-k+1,0);
    int vpi = 0;
    for(int i= 0;i<k;i++){
        pq.push({arr[i],i});
    }
    vp[vpi]=pq.top().first;
    vpi++;
    for(int i = k;i<n;i++){
        pq.push({arr[i],i});
        while(pq.size()>0&& i-pq.top().second>=k) pq.pop();
        
        if(pq.size()>=k){
            vp[vpi] = pq.top().first;
            vpi++;
        }
    }
    return vp;
    }
};