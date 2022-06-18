class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>temp;
        for(int i = 0;i<strs.size();i++){
            string chal = strs[i];
            sort(chal.begin(),chal.end());
            temp.push_back({chal,i});
        }
    sort(temp.begin(),temp.end());
        vector<vector<string>>ans;
        string prev = "zero";
        vector<string>st;
        for(int i = 0;i<temp.size();i++){
            string temp2 = temp[i].first;
            int ind = temp[i].second;
            if(prev=="zero"){
                st.push_back(strs[ind]);
                prev = temp2;
            }
            else if(prev==temp2){
                st.push_back(strs[ind]);
                
            }
            else if(prev!=temp2){
                ans.push_back(st);
                st.clear();
                st.push_back(strs[ind]);
                prev = temp2;
            }
        }
        if(st.size()) ans.push_back(st);
        return ans;
    }
};