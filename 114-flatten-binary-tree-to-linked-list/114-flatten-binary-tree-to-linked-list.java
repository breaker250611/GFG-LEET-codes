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
    public TreeNode head = new TreeNode();
    public TreeNode seedhakarna(TreeNode root){
        
        if(root ==null) return root;
        TreeNode templeft = new TreeNode();
        TreeNode tempright = new TreeNode();
        
        head = root;
        templeft = seedhakarna(root.left);
        root.left = null;
        TreeNode aaega = new TreeNode();
        aaega = head;
        tempright = seedhakarna(root.right);
        
        root.right = templeft;
        aaega.right = tempright;
        return root;
        
        
    }
    public void flatten(TreeNode root) {
        // TreeNode head = new TreeNode();
        root = seedhakarna(root);
        
    }
}