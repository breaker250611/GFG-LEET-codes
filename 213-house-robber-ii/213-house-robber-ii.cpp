class Solution {
public:
    int rob(vector<int>& num) {
        long long int lo = num[0];
    long long int ch = 0;
    for(int i = 1;i<num.size()-1;i++){
        long long int nlo = ch+num[i];
        long long int nch = lo;
        lo = max(nlo,lo);
        ch =max( nch,ch);
    }
         long long int nnlo = 0;
    long long int nnch = 0;
        
    if(num.size()>1){
          nnlo = num[1];
     nnch = 0;
    for(int i = 2;i<num.size();i++){
        long long int nlo = nnch+num[i];
        long long int nch = nnlo;
        nnlo = max(nnlo,nlo);
        nnch = max(nnch,nch);
    }
    }
    return max({lo,ch,nnlo,nnch}); 
    }
};