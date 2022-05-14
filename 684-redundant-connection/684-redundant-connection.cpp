class UnionFind {
    public: 
    vector<int> p, s;
    UnionFind(int n) {
        p.resize(1001, 0);
        s.resize(1001, 1);
        iota(p.begin(), p.end(), 0);
    }
    
    int find(int n) { return n == p[n] ? n : p[n] = find(p[n]); }
    bool same(int a, int b) { return find(a) == find(b); }
    void merge(int a, int b) {
        a = find(a); 
        b = find(b); 
        if (a == b) 
            return; 
        if (s[a] < s[b]) 
            swap(a, b); 
        p[b] = a; 
        s[a] += s[b];
    }
};

class Solution {
    public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind dsu(0);
        vector<int> ans;
        for (const auto& i: edges) {
            int a = i[0]; 
            int b = i[1]; 
            if (dsu.same(a, b)) {
                ans = {a, b};
                break;
            }
            else {
                dsu.merge(a, b);
            }
        }
        return ans;
    }

};