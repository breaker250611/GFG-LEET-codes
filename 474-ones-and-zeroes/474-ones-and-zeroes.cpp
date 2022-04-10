#define f first
#define s second
#define vpi vector<pair<int , int>>
#define  pb push_back 
class Solution {
public:
    
    int func (vpi &ar , int i , int m , int n , int dp[601][101][101]){
        if ( i >= ar.size()){
            return 0;
        }
        
        // if (m < 0 or n < 0) return 0;
       // if (m == 0 and n == 0) return 0;
        if (dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        
       int op2 =  0 + func (ar , i+1 , m , n , dp); 
       int op1 =0;
       if (m-ar[i].f >= 0 and n-ar[i].s >= 0) {
           op1  =  1 + func(ar , i+1 , m-ar[i].f , n-ar[i].s , dp);
       }
        
       return dp[i][m][n] = max(op1 , op2); 
    }
    
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vpi ar;
        for (auto x : strs){
            int a = 0 , b = 0;
            for (auto y : x){
                y == '1' ? a++ : b++;
            }
            ar.pb({b , a});
        }
        int dp[601][101][101];
        for (int i = 0 ; i<=600 ; i++){
            for (int j = 0 ; j<=100 ; j++){
                for (int k = 0 ; k <= 100 ; k++){
                 dp[i][j][k] = -1;
                }
            }
        }
        return func(ar , 0 , m , n , dp);
    }
};