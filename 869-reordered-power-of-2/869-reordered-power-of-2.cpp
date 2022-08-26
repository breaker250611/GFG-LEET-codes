class Solution {
public:
    int digits(int n) {
        int count = 0;
        while (n) {
            count ++; 
            n /= 10;
        }
        return count;
    }
    
    bool reorderedPowerOf2(int n) {
        int i = 1; 
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        while (digits(i) <= digits(n)) {
            string t = to_string(i);
            sort(t.begin(), t.end());
            if (t == s) {
                return true;
            }
            i *= 2;
        }
        return false;
        
    }
};