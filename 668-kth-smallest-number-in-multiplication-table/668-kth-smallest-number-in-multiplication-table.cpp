class Solution {
public:
     bool good(int n , int m , int val , int k){
    
        int count = 0;
        int i = 1 , j = m;
        
        while (i > 0 and j > 0 and i <= n and j <= m){
            if ((i*j) > val){
                j--;
            }
            else {
                count += j;
                i++;
            }
        }
        return count >= k;
    }
    int findKthNumber(int m, int n, int k) {
         
        int low = 0 , high = m*n;
        int ans = 0;
        while (low <= high){
            int mid = (low + high)/2;
            cout << mid << endl;
            if (good(n , m , mid , k)){
                ans = mid;
                high = mid-1;
            }
            else{
               low = mid+1;   
            }
        }
        return ans;
    }
};