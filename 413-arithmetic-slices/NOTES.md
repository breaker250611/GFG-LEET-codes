```
class Solution {
public int numberOfArithmeticSlices(int[] nums) {
if (nums.length < 3) return 0;
int d = nums[1] - nums[0];
int l = 2, totans = 0;
for (int i = 1; i < nums.length-1; i++) {
if (d == (nums[i+1] - nums[i]))
l += 1;
else {
totans += ((l-1)*(l-2))/2;
d = nums[i+1] - nums[i];
l = 2;
}
}
totans += ((l-1)*(l-2))/2;
return totans;
}
}
```
chutu vaii tareeka
​
ya fir ese soch jese 1 2 3 4 5 6  bni h AP to isme l = 6 he ab subarrays bnane he to isme se l=5 ke bna skta he 4 ke 3 ke to total ho jaenge : 1(6 len vala) +2(5 len vale)+ 3(4 len vale) + ... + 4(3 len vale)
generalise kr : 1+2+..... +l-2
sum of first l-2 natural numbers he ye