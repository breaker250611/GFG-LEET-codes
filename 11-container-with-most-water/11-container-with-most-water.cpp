class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size()-1;
        int mxarea = 0;
        while(lo<hi){
            int temp = min(height[lo],height[hi]);
            int temparea = temp*(hi-lo);
            mxarea = max(mxarea,temparea);
            if(height[lo]>height[hi])hi--;
            else lo++;
        }
        return mxarea;
    }
};