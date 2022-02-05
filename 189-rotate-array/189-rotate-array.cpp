class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        k = n-k;
        int begin = 0;
        int end = k-1;
        while(begin<end){
            swap(nums[begin],nums[end]);
            begin++;
            end--;
        }
        begin = k;
        end = n-1;
        while(begin<end){
                        swap(nums[begin],nums[end]);
            begin++;
            end--;
            
        }
        reverse(nums.begin(),nums.end());

    }
};