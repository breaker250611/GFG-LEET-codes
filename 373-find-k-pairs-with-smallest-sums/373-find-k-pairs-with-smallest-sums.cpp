typedef pair<int, vector<int>> pi;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi>pq;
        int i = 0;
        bool flag = false;
        int j = 0;
        for(i = 0;i<nums1.size();i++){
            for( j = 0;j<nums2.size();j++){
                if(pq.size()<k){
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});   
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
        int p = i;
        for(i;i<nums1.size();i++){
            for(j=(p==i)?j:0;j<nums2.size();j++){
                int temp = nums1[i]+nums2[j];
                if(temp<pq.top().first){
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});  
                    
                }
                else break;
            }
        }
        vector<vector<int>>vp;
        while(pq.size()>0){
            vp.push_back(pq.top().second);
            pq.pop();
        }
        sort(vp.begin(),vp.end());
        return vp;
    }
};