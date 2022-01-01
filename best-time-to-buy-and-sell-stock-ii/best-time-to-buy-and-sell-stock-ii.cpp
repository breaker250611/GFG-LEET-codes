class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyki = -prices[0];
        int sellki = 0;
        for(int i=1;i<prices.size();i++){
            int nayabuy = max(buyki,-prices[i]+sellki);
            int nayasell = max(sellki , buyki+prices[i]);
            buyki = nayabuy;
            sellki = nayasell;
        }
        return sellki;
    }
};