class Solution {
    public int maxArea(int[] height) {
        int begin = 0;
        int end = height.length-1;
        int maxiarea = 0;
        
        while(begin<end){
            int height1 = height[begin];
            int height2 = height[end];
            
            int miniheight = Math.min(height1,height2);
            
            int temparea = miniheight*(-begin+end);
            if(maxiarea<temparea) maxiarea = temparea;
            
            if(height1<height2) begin++;
            else end--;
        }
        return maxiarea;
    }
}