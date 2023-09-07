class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];
        
        for(int i = 1;i<prices.size();i++){
            int diff = prices[i]-buy;
            
            if(diff<0){
                buy = prices[i];
            }
            ans = max(ans,diff);
        }
        return ans;
        
    }
};