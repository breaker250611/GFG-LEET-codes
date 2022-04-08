class Solution {
public:
    vector<string> res;
    int n;
    vector<string> restoreIpAddresses(string s)
    {
        n = s.size();
        f(s, "", 4, 0);
        return res;        
    }
    
    void f(string &s, string t, int k, int pos)
    {
        if (pos == n)
        {
            if (k == 0)
            {
                t.pop_back();
                res.push_back(t);
                
            }
            
            return;
        }
        
        for (int i = pos; i < n; i++)
        {
            if (i != pos && s[pos] == '0') continue;
            string x = s.substr(pos, i - pos + 1);
            int v = stoi(x);
            if (v > 255) break;
            
            f(s, t + x + '.', k - 1, i + 1);
        }
    }
};