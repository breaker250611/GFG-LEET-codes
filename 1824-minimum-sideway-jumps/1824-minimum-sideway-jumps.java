class Solution { 
    public int minSideJumps(int[] obstacles) {
	    // 4 rows (lanes) -0,1,2,3 (ignore 0th row) || obstacles.length columns
        int dp[][] = new int[4][obstacles.length];
        for(int[] a : dp)
         Arrays.fill(a, -1); // fill whole dp with -1;
		 
        return minSideJumps( obstacles, 0, 2, dp); // start at 0th point at 2nd lane,
    }
    
    private int minSideJumps(int [] ob, int p, int lane, int dp[][]){
        if(p == ob.length-1) return 0;             // reached last point 
        if( ob[p]==lane) return Integer.MAX_VALUE; // if encountered an obstacle
        if(dp[lane][p]!=-1) return dp[lane][p];    // if sub problem already solved
        
        if(ob[p+1]!=lane){                    // if the next point in lane has no obstacle
             dp[lane][p] =  minSideJumps(ob, p+1, lane, dp);
        }else{                                // if the next point in lane has  obstacle then we have 2 choices
            int l1 = lane-1 !=0 ? lane-1 : lane+2;
            int l2 = lane+1!=4 ? lane+1 : lane-2;
                                                //get the min of two choices
             dp[lane][p] =  1+ Math.min(minSideJumps(ob, p, l1, dp), minSideJumps(ob, p, l2, dp)); 
        }
        return  dp[lane][p];
    }
}