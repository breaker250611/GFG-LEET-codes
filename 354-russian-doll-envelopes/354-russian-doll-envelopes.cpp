static bool comparator(const vector<int>& one, const vector<int>& two) {
    if (one[0] == two[0]) return one[1] > two[1];
    return one[0] < two[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comparator);
        
        vector<int> arr;
        
        for (int i = 0; i < n; i++) {
            int current = envelopes[i][1]; 
            auto it = lower_bound(arr.begin(), arr.end(), current);
            if (it == arr.end()) {
                arr.push_back(current);
            } else {
                arr[it - arr.begin()] = current;
            }
        }
        
        return arr.size();
    }
};