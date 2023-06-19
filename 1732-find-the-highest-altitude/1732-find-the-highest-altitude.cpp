class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     int fin = 0;
        int ans = 0;
        
        
        for(int i = 0;i<gain.size();i++){
            ans += gain[i];
            fin = max(fin,ans);
        }
        return fin;
    }
};