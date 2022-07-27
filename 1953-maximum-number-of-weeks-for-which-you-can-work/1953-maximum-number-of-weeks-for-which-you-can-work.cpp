class Solution {
    public:
    using ll = long long int;
    long long numberOfWeeks(vector<int>& arr) {
        if (arr.size() == 1) {
            return 1;
        }
        ll mx = *max_element(arr.begin(), arr.end()); 
        ll sum = accumulate(arr.begin(), arr.end(), 0LL);
        sum -= mx;

        if (sum < mx) {
            return 2 * sum + 1;
        }
        return sum + mx;
    }
};