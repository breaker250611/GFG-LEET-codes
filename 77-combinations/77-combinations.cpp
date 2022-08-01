class Solution {
    public:
    vector<int> temp;
    vector<vector<int>> ans;
    int n, k;

    void fun(int i) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        if (i > n) return;
        
        // elements currently < elements needed.
        if ((n - i + 1) < (k - temp.size())) return;

        fun(i + 1); 
        
        temp.push_back(i); 
        fun(i + 1); 
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n; 
        this->k = k; 

        fun(1);

        return ans;

    }
};