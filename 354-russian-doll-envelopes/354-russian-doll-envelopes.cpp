static bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    else return a[0]<b[0];
}
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& e) {
         int n = e.size();
        sort(e.begin() , e.end() , cmp);
        vector<int> t;
        for (int i = 0 ; i<e.size() ; i++){
            auto it = lower_bound(t.begin() , t.end() , e[i][1]);
            
            if (it == t.end()){
                t.push_back(e[i][1]);
            }
            else{
               t[it-t.begin()] = e[i][1];   
            }
        }
        return t.size();
    }
};