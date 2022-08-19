class Solution {
public:
    int balancedString(string s) {
        map<char,int>mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans = INT_MAX;
        int lo = 0;
        int i = 0;
        int req = (s.size())/4;
        while(i<s.size()){
            mp[s[i]]--;
            while(mp['Q']<=req  and mp['W']<=req and mp['E']<=req and mp['R']<=req and lo<=s.size()){
        
                mp[s[lo]]++;
                ans = min(ans,i-lo+1);
                lo++;
            }
           i++;
        }
        return ans;
    }
};