class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxipro = 0;
        int buyki = prices[0];
        
        for(int i = 1;i<prices.size();i++){
            int usdin = prices[i];
            int temp = usdin-buyki;
            maxipro = max(maxipro,temp);
            if(usdin<buyki) buyki = usdin;
        }
        return maxipro;
        
    }
};