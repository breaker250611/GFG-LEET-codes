class Solution {
public:
    void removeduplicate(vector<int>&arr2,vector<int>&array2){
         int prev = -1;
        for(int i = 0;i<arr2.size();i++){
            
            if(prev != -1){
                if(prev==arr2[i])continue;
                else{
                    array2.push_back(arr2[i]);
                    prev = arr2[i];
                }
            }
            else if(prev==-1){
                array2.push_back(arr2[i]);
                prev = arr2[i];
            }
        }
        return;
    }
    

    // vector<vector<int>>dp;
    map<pair<int,int>,int>dp;
    
    int call(vector<int>&arr1,vector<int>&arr2,int i , int prev){
        if(i==arr1.size())return 0;
        // for(auto&it:arr2)cout<<it<<" "<<endl;
        if(dp.find({i,prev}) != dp.end()){
            // cout<<"an"<<endl;
            return dp[{i,prev}];
        }
        
        long long int take = 2005;
        long long int nottake = 2005;
        int ind = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        // ind--;
        // cout<<ind<<endl;
        
        
        if(arr1[i]>prev){
            nottake = call(arr1,arr2,i+1,arr1[i]);
            // cout<<nottake<<endl;
        }
        
        
        if(ind<arr2.size()){
            if(arr2[ind]==arr1[i]){}
            else{ 
                // cout<<arr2[ind]<<endl;
                take = call(arr1,arr2,i+1,arr2[ind])+1;}
            // cout<<take<<endl;
        }
        
        int ans = min(take,nottake);
        
        dp[{i,prev}] = ans;
        return ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<int>array2;
        removeduplicate(arr2,array2);
        // dp.resize(vector<int>(arr1.size(),0));
        dp.clear();
        
        int ans =  call(arr1,array2,0,-1);
        // cout<<dp.size();
        if(ans ==2005) ans = -1;
        return ans;
    }
};