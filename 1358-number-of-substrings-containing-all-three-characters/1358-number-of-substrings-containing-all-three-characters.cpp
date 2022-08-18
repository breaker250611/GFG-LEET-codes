class Solution {
    public:
    int numberOfSubstrings(string s) {
        using ll = long long int;
        
        int a = 0; 
        int b = 0; 
        int c = 0; 
        ll count = 0; 
        ll n = s.size();

        int l = 0; 
        for (int r = 0; r < n; r++) {
            a += (s[r] == 'a');
            b += (s[r] == 'b');
            c += (s[r] == 'c');

            while (l < r && a >= 1 && b >= 1 && c >= 1) {
                a -= (s[l] == 'a');
                b -= (s[l] == 'b');
                c -= (s[l] == 'c');
                l ++;
            }

            count += (r - l+1);
        }


        return int(n * (n + 1)/2 - count);
    }
};