const int mod = 1e9+7;
class Solution {
public:
    /*
    mp[36] = mp[36] + mp[9]*mp[4];
    
    */
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<long long int,long long int>mp;
        
        sort(arr.begin(),arr.end());
        
        for(int i = 0 ;i<arr.size();i++){
            mp[arr[i]] = 1;
            int karna = arr[i];
            for(int j = 0;j<i;j++){
                if(karna%arr[j]==0){
                    int temp = karna/arr[j];
                    if(mp.count(temp)){
                        mp[arr[i]] =(mp[arr[j]]*mp[temp]+mp[arr[i]])%mod;
                    }
                }
            }
         }
        
        long long int sum = 0;
        for(auto &it:mp){
            sum =( sum +it.second)%mod;
        }
        return sum;
    }
};