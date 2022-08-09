class Solution {
public:

long long C(int n, int r) {
    if(n<3)return 0;
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = 0;
        if(nums.size()<3)return 0;
        while(i<nums.size() and nums[i] == 0)i++;
        int total = C(nums.size()-i,3);
        int tutu = i;
        // cout<<"tutu "<<tutu<<endl;
        // cout<<"teota "<<total<<endl;
        for(int i = tutu;i<nums.size();i++){
            for(int j = tutu;j<i;j++){
                int temp = nums[i]+nums[j];
                
                int x = lower_bound(nums.begin(),nums.end(),temp)-nums.begin();
                int addkar = nums.size()-x;
                count +=addkar;
            }
        }
        int ans =  total-count;
        if(ans<0)return 0;
        return ans;
    }
};