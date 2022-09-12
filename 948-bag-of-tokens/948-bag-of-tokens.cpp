class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int lo = 0;
        int hi  = tokens.size()-1;
        int p = 0;
        
        int ans = 0;
        while(lo<=hi){
            if(power>=tokens[lo]){
                p++;
                power -= tokens[lo++];
                ans = max(ans,p);
            }
            else if(p>0){
                p--;
                power += tokens[hi--];
            }
            else break;
        }
        return ans;
    }
};