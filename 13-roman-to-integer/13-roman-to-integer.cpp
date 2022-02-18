class Solution {
public:
    int romanToInt(string numeral) {
        map<char ,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']= 1000;
        stack<int>st;
        for(int i=0;i<numeral.size();i++){
                int temp = mp[numeral[i]];
                st.push(temp);
        }
        int ans = 0;
        int prev = 0;
        while(st.size()){
                int temp = st.top();
                
                st.pop();
                if(temp<prev){
                        ans = ans-temp;
                }
                else ans +=temp;
                prev = temp;
        }
        return ans;
    }
};