class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0) return ans;
        int begin= nums[0];
        int end = nums[0];
        
        for(int i=1;i<nums.size();i++){
            // if(begin==0&&end==0){
            //     begin =nums[i];
            //     end = nums[i];
            // }
             if(nums[i]==end+1) end = nums[i];
            else{
                if(begin==end){
                 string str = to_string(begin);   
                 ans.push_back(str);
                }
                    else{
                    string str =to_string(begin);
                    str = str+"->";
                    str = str+to_string(end);
                    ans.push_back(str);
                }
                begin = nums[i];
                end = begin;
            }
        }
         if(begin==end){
                 string str = to_string(begin);   
                 ans.push_back(str);
                }
                    else{
                    string str =to_string(begin);
                    str = str+"->";
                    str = str+to_string(end);
                    ans.push_back(str);
                }
                // begin = nums[i];
                // end = begin;
            
        return ans;
    }
};