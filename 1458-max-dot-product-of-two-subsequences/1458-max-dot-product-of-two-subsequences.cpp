class Solution {
    public:
    vector<int> arr, brr;
    vector<vector<int>> dp; 
    int n, m;

    int fun(int i, int j) {
        if (i == n or j == m) {
            return -1e5;
        }

        int &ans = dp[i][j]; 
        if (ans == -1) {
            ans = max({
                arr[i] * brr[j], 
                fun(i + 1, j + 1) + arr[i] * brr[j], 
                fun(i, j + 1), 
                fun(i + 1, j)
            });
        }
        return ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(); 
        m = nums2.size();
        arr = nums1; 
        brr = nums2;
        dp.resize(n + 1, vector<int>(m + 1, -1));

        return fun(0, 0);
    }
};