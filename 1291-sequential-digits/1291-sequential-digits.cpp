class Solution {
public:
    vector<int> ans;
    
    void func(long val , int low , int high){
    
        if (val > high) return;
        
        if (val >= low and val <= high){
            ans.push_back(val);
        }
        
        int last = val%10;
        if (last == 9) return;
        func(val*10 + (++last) , low , high);
        return;  
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for (int ch = 1 ; ch <= 9 ; ch++){
            func(ch , low , high);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};
