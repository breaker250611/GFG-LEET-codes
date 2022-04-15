class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>pos(nums.size(),1),neg(nums.size(),1);
   for(int i = 0;i<nums.size();i++){
       for(int j = 0;j<i;j++){
           if(nums[i]-nums[j]==0) continue;
           else if(nums[i]-nums[j]>0){
               pos[i]= max(pos[i],neg[j]+1);
           }
           else if(nums[i]-nums[j]<0){
               neg[i]= max(neg[i],pos[j]+1);
           }

       }
   }
        int m = *max_element(neg.begin(),neg.end());
        int n = *max_element(pos.begin(),pos.end());
        return max(n,m);
        }
};