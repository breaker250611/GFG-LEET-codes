bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        
        int maxdef = properties[0][1];
        int count = 0;
        
//         for(auto &it:properties){
//             for(auto &i:it)  cout<<i<<" ";
//             cout<<endl;
//         }
        for(int i = 1;i<properties.size();i++){
            if(properties[i][1]<maxdef) count++;
            
            maxdef = max(maxdef,properties[i][1]);
        }
        return count;
    }
};