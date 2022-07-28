class Solution {
public:
    bool isAnagram(string s, string t) {
       int arr[26]={0};
        for(auto val:s){
            arr[val-'a']++;
        }
        for(auto val:t){
            arr[val-'a']--;
        }
        for(auto val:arr){
            if(val!=0) return false;
        }
        return true;
        
    }
};