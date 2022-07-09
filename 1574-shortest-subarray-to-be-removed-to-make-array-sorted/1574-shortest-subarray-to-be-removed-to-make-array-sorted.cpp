class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int start = 0;
        int end_ka = arr.size()-1;
        
        for(start=0;start<arr.size()-1;start++){
            if(arr[start]>arr[start+1]) break;
            // /start++;
        }
        if(start==arr.size()-1) return 0;
        // start--;
        for(end_ka;end_ka>0;end_ka--){
            if(arr[end_ka]<arr[end_ka-1]) break;
            
        }
        if(end_ka==0) return arr.size()-1;
        // end_ka++;
        int n = arr.size();
        int ans = min(n-start-1,end_ka);
        int i = 0;
        while(i<=start && end_ka<arr.size()){
            if(arr[i]<=arr[end_ka]){
                ans = min (ans,end_ka-i-1);
                i++;
            }
            else end_ka++;
        }
        return ans;
    }
};