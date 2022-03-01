class Solution {
public:
//     int cnt(uint32_t n){
        
//     }
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            int rsb = n&-n;
            n = n-rsb;
            cnt++;
        }
        return cnt;
    }
};