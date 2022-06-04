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
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        
        if (root.left != null) {
            TreeNode startLeft = root.left; 
            TreeNode endLeft = root.left; 
            TreeNode connectWithRight = root.right; 
            
            while (endLeft.right != null) {
                endLeft = endLeft.right;
            }
            
            root.right = startLeft; 
            endLeft.right = connectWithRight;
            root.left = null; 
        }
        
        flatten(root.left); 
        flatten(root.right); 
        
    }
}