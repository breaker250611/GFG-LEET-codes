class Solution {
    public int rob(int[] nums) {
        int choriki = nums[0];
        int nhiki = 0;
        for(int i=1;i<nums.length;i++){
            int maal = nums[i];
            
            int newchori = maal+nhiki;
            newchori = Math.max(choriki,newchori);
            int dobaranhiki = Math.max(choriki,nhiki);
            
            choriki=newchori;
            nhiki = dobaranhiki;
        }
        return choriki;
        
    }
}