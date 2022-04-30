class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        set<string> st;
        map<string , int> in;
        map<string , vector<string>> g;
         
        for (int i = 0 ; i<recipes.size() ; i++){
            st.insert(recipes[i]);
            for (auto x : ingredients[i]){
                g[x].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }
        
        for (auto x : supplies){
            in[x] = 0;
        }
        
        queue<string> q;
        
        for (auto x : in){
            if (x.second == 0){
                q.push(x.first);
            }
        }
        vector<string> ans;
        while (!q.empty()){
            string c = q.front(); q.pop();
            if (st.count(c)){ans.push_back(c);}
            for (auto x : g[c]){
                in[x]--;
                if (in[x] == 0){
                    q.push(x);
                }
            }
        }
        return ans;
    }
};