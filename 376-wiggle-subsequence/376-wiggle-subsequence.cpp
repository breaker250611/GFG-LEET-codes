class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n, 1), neg(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int diff = nums[i] - nums[j];
                if (diff == 0) 
                    continue; 
                else if (diff > 0) 
                    pos[i] = max(pos[i], neg[j] + 1);
                else 
                    neg[i] = max(neg[i], pos[j] + 1);
            }
        }
        return max(pos.back(), neg.back());
    }
};