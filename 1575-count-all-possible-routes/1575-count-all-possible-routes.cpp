const long long int mod= 1e9+7; 
class Solution {
public:
    vector<vector<int>>dp;
    
    int call(vector<int>& locations, int start,int finish,int fuel){
        if(start==finish and fuel==0) return 1;
        else if(start==finish and fuel>0){
            int &temp = dp[start][fuel];
            if(temp == -1)
            { temp = 1;
              for(int i = 0 ;i<locations.size();i++){
                if(i==start)continue;
                int minus = abs(locations[i]-locations[start]);
                temp =(temp%mod + call(locations,i,finish,fuel-minus)%mod)%mod;
            }
            }
            return temp;
        }
        if(start==locations.size() or fuel<0) return 0;
        
        int &ans = dp[start][fuel];
        if(ans ==-1){
            ans = 0;
            for(int i = 0 ;i<locations.size();i++){
                if(i==start)continue;
                int minus = abs(locations[i]-locations[start]);
                ans = ((ans)%mod +(call(locations,i,finish,fuel-minus))%mod)%mod;
            }
        }
        return ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.resize(locations.size()+1,vector<int>(fuel+1,-1));
        return call(locations,start,finish,fuel);
        int count = 0;
        for(int i = 0;i<=fuel;i++){
            
            if(dp[finish][i] !=-1) count +=dp[finish][i];
        }
        return count;
    }
};