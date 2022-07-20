class Solution {
    public int largestRectangleArea(int[] heights) {
        //left next smallest element
        int[] lb = new int[heights.length];
        Stack<Integer> st = new Stack<>();
        st.push(0);
        lb[0]= -1;
        for(int i=1;i<heights.length;i++){
            while(st.size()>0&& heights[i]<=heights[st.peek()]){
                st.pop();
            }
             if(st.size()==0){
                lb[i] = -1;
            }
            else{
                lb[i] = st.peek();
            }
            st.push(i);
        }
        while(st.empty()!=true){
            st.pop();
        }
        //right next smallest element
        int[] rb = new int[heights.length];
        st.push(heights.length-1);
        rb[heights.length-1]= heights.length;
        for(int i=heights.length-2;i>=0;i--){
            while(st.size()>0&& heights[i]<=heights[st.peek()]){
                st.pop();
            }
            if(st.size()==0){
                rb[i] = heights.length;
            }
            else{
                rb[i] = st.peek();
            }
            st.push(i);
        }
         //area
        int maxarea = 0;
       for(int i=0;i<heights.length;i++){
           int width = rb[i]-lb[i]-1;
           int area = width*heights[i];
           if(area>maxarea) maxarea = area;
       }
        return maxarea;   
    }
}