class Solution {
    public int findComplement(int n) {

        return n == 0 ? 1 : ((1 << Integer.toBinaryString(n).length()) - 1) ^ n;
    

    }
}