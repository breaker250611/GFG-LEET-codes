class KthLargest {
public:
    int kth;
    vector<int> no;
priority_queue <int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        no = nums;
        for(int i = 0;i<nums.size();i++){
            if(pq.size()<kth){
                pq.push(nums[i]);
            }
            else{
                if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
       no.push_back(val);
        if(pq.size()==0||pq.size()<kth){
            pq.push(val);    
        }
        else if(pq.top()<val)
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */