class Solution {
public:
    int n , m;
    bool good(vector<vector<int>> &mat, int val , int k){
        
        int count = 0;
        int i = 0 , j = m-1;
        
        while (i >= 0 and i < n and j >= 0 and j < m){
            if (mat[i][j] > val){
                j--;
            }
            else{
                count += j+1;
                i++;
            }
        }
        return count >= k;
    }
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        n = matrix.size();
        m = matrix[0].size();
        
        int low = matrix[0][0] , high = matrix[n-1][m-1];
        int ans = 0;
        while (low <= high){
            int mid = (low + high)/2;
            cout << mid << endl;
            if (good(matrix , mid , k)){
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