class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t rev = 0;
        bool flag = false;
        int j = 0;
        for(int i = 31;i>=0;i--){
            if(flag){
                if((n & (1<<i))!= 0){
                    rev |= (1<<j);
                }
                    j++;
            }
            else{
                if((n & (1<<i))!= 0){
                    flag = true;
                    rev |= (1<<j);
                }
                else{
                    
                }
                    j++;
            }
        }
        return rev;
    }
};