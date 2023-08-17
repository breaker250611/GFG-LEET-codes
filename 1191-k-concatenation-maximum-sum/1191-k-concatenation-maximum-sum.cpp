long long int MOD = 1e9+7;
class Solution {
public:
   
    
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum =0;
        int maxsub = 0;
        int temp = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i]%MOD;
            temp += arr[i]%MOD;
            maxsub = max(maxsub,temp);
            if(temp<0){
                temp = 0;
            }
        }
        if(k==1) return maxsub;
        for(int i = 0;i<arr.size();i++){
            temp+=arr[i];
            maxsub = max(maxsub,temp);
            if(temp<0) temp = 0;
        }
        
        
        
        if(sum<0){
            return maxsub;
        }
        else{
            long long int ans = (maxsub%MOD*1LL + (1LL*sum*(k-2))%MOD)%MOD;
            return ans;
        }
        return 0;
    }
};