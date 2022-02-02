// { Driver Code Starts
//Initial Template for Java



import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().findMaxSum(arr, n);
            System.out.println(ans);
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution {
    int findMaxSum(int nums[], int n) {
        // code here
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