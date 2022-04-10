class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int buy = 0;
        int sell = 0;
        
        buy = -nums[0];
        for(int i =1;i<nums.size();i++){
            int nayabuy = 0;
            int nayasell = 0;
            
            nayabuy = sell-(nums[i]);
            nayasell = nums[i]+(buy)-fee;
            
            if(nayabuy>buy) buy = nayabuy;
            if(nayasell>sell) sell = nayasell;
        }
        return sell;
        
    }
};