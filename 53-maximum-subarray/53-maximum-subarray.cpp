class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxi = INT_MIN;
        int tempmaxi = arr[0];
        
        for(int i = 1;i<arr.size();i++){
            maxi = max(maxi,tempmaxi);
            if(tempmaxi<0){
                tempmaxi = arr[i];
            }
            else tempmaxi +=arr[i];
        }
        maxi = max(maxi,tempmaxi);

        return maxi;
        
    }
};