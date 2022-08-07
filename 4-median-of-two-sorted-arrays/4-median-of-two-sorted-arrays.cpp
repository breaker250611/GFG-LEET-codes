class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int total = nums1.size()+nums2.size();
        int first = (total+1)/2;
        int second = total - first;
        
        int lo = 0;
        int hi  = nums1.size();
        while(lo<=hi){
            int mid = (lo+hi)/2;
            
      
            int upr = mid;
            int neech = first-mid;
            cout<<neech<<endl;
            int l1 = (upr==0)?INT_MIN:nums1[upr-1];
            int l2 = (neech==0)?INT_MIN:nums2[neech-1];
                      cout<<"check"<<endl;
            int r1 = (upr==nums1.size())?INT_MAX:nums1[upr];
            int r2 = (neech==nums2.size())?INT_MAX:nums2[neech];
            
            if(l1>r2) hi = mid-1;
            else if(l2>r1) lo = mid+1;
            else {
                        if(total%2==0){        
                double ans =max(l1,l2)/2.0 + min(r1,r2)/2.0 ;
                    return ans;
                        }
                else{
                    return max(l1,l2);
                }
                
            }
            
        }
        return -1;
    }
};