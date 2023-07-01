class Solution {
public:
    vector<int>bacha;
    int ans = 0;
    
    
    void call(vector<int>&cookies,int k,int i){
        if(cookies.size()==i){
            int temp = *max_element(bacha.begin(),bacha.end());
            ans = min(ans,temp);
            return;
        }
        
        for(int j = 0;j<k;j++){
            bacha[j] +=cookies[i];
            call(cookies,k,i+1);
            bacha[j] -= cookies[i];
        }
        return;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        bacha.resize(k,0);
        ans = INT_MAX;
        
        call(cookies,k,0);
        return ans;
    }
};