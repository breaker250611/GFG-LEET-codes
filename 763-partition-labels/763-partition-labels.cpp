class Solution {
public:
    vector<int> partitionLabels(string s) {
         map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]=i;
    }
    vector<int>ans;
    int count = 0;
    int hi = 0;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        hi = (mp[ch]>hi)?mp[ch]:hi;
        if(hi==i){
            ans.push_back(count+1);
            count =0;
        }
        else{
            count++;
        }
        
    }
    return ans;
    }
};