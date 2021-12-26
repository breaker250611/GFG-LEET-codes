class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector <pair<double,int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            double temp = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            cout<<temp<<endl;
            mp.push_back({temp,i});
        }
        sort(mp.begin(),mp.end());
        for(int i=0;i<k;i++){
            int ind = mp[i].second;
            ans.push_back(points[ind]);
        }
        return ans;
        
    }
};