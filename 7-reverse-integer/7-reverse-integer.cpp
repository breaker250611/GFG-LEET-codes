class Solution {
public:
    int reverse(int x) {
        int sign = (x>0)?1:-1;
        
        long  num = 0;
        while(x){
            int rem = x%10;
             x = x/10;
            num = num*10 + rem;
            if(num>INT_MAX or num<INT_MIN) return 0;
        }
        
        // num = num;
        return num;
    }
};