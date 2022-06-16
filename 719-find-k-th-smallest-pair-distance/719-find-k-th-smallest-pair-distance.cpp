class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = 1;
        while(i<n&&j<n){
            while(abs(nums[i]-nums[j])>mid) i++;
            count += j-i;
            j++;
        }
        if(count>=k)return true;
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int lo = 0;
        int hi = nums[nums.size()-1]-nums[0];
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(nums,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};