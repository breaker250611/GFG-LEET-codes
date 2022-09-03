class Solution {
public:
    vector<int>cnt;
    void call(int n , int k,int i,string temp){
        if(temp.size()==n) {cnt.push_back(stoi(temp));return;}
        if(i-k>=0){
            string tmp = to_string(i-k);
            call(n,k,i-k,temp+tmp);
        }
        if(i+k<=9 and k!=0){
            string tmp = to_string(i+k);
            call(n,k,i+k,temp+tmp);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1;i<=9;i++){
            string temp = to_string(i);
        call(n,k,i,temp);
            
        }
        return cnt;
    }
};