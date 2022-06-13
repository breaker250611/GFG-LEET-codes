class Solution {
public:
    bool bansaktahai(vector<int>& position, int m,int dis){
        int prev = position[0];
        m--;
        for(int i = 0;i<position.size();i++){
            if(position[i]-prev>=dis){
                prev = position[i];
                m--;
            }
        }
        if(m<=0)return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo = 1;
        int hi = position[position.size()-1];
        
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            if(bansaktahai(position,m,mid)){
                lo = mid+1;
            }
            else{
                hi  = mid-1;
            }
        }
        return hi;
    }
};