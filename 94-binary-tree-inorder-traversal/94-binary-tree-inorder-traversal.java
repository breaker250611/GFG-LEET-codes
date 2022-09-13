/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
         
        if(root==null) {
            List<Integer>temp = new ArrayList<Integer>();
            return temp;
        }
            List<Integer> l1 = new ArrayList<Integer>();
            
            List<Integer> l2 = inorderTraversal(root.left);
           
            List<Integer>l3 = inorderTraversal(root.right);
        
            for(Integer x:l2) l1.add(x);
         l1.add(root.val);
        for(Integer x:l3) l1.add(x);
        return l1;

    }
}