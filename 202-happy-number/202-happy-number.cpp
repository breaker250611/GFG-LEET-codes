class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        
        while(n!=1){
            int temp = 0;
            while(n){
                int rem = n%10;
                temp += rem*rem;
                n = n/10;
            }
            n = temp;
            if(mp.find(n) !=mp.end()){
                return false;
            }
            mp[n]++;
        }
        return true;
    }
};