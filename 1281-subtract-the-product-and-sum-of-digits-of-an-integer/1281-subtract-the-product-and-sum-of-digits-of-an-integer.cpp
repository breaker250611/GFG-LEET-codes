class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1;
        int sum = 0;
        while(n){
            int rem = n%10;
            sum +=rem;
            pro *=rem;
            n /=10;
        }
        return pro-sum;
    }
};