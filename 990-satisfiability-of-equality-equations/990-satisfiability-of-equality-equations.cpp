class Solution {
public:
    vector<int>parent,rank;
    static bool cmp(string &a,string &b){
        return a[1]>b[1];
    }
    int find (int a ){
        if(parent[a] ==a) return a;
        return parent[a]=find(parent[a]);
    }
    void _union(int a , int b){
        int la = find(a);
        int lb = find(b);
        if(la!=lb){
            if(rank[la]>rank[lb]) parent[lb] = la;
            else if(rank[lb]>rank[la]) parent[la] = lb;
            else{
                parent[lb]= la;
                rank[la]++;
            }
        }
    }
    bool check(int a , int b){
        int la = find(a);
        int lb = find(b);
        if(la==lb) return false;
        return true;
    }
    bool equationsPossible(vector<string>& eq) {
        sort(eq.begin(),eq.end(),cmp);
        parent.resize(301,0);
        rank.resize(301,0);
        for(int i = 0;i<=300;i++){
            parent[i] = i;
        }
        for(auto x:eq){
            if(x[1]=='='){
                _union(x[0],x[3]);
            }
            else{
                bool f = check(x[0],x[3]);
                if(!f) return false;
            }
        }
        return true;
    }
};