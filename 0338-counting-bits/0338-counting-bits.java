class Solution {
    public int[] countBits(int n) {
        int[] temp = new int[n+1];
        
        for(int i = 0;i<=n;i++){
            int num = i;
            int count = 0;
            while(num>0){
                int x = num&1;
                if(x==1)count++;
                
                num = num>>1;
            }
            temp[i] = count;
            
        }
        
        
        return temp;
    }
}