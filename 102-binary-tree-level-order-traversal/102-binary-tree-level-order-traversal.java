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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>ans = new ArrayList<List<Integer>>();
        if(root==null) return ans;
        Queue<TreeNode> mq = new ArrayDeque<>();
        mq.add(root);
        while(mq.size()!=0){
            List<Integer> temp1 = new ArrayList<Integer>();
            int count = mq.size();
            for(int i =0;i<count;i++){
                TreeNode temp = mq.remove();
                int data = temp.val;
                temp1.add(data);
                if(temp.left!=null) mq.add(temp.left);
                if(temp.right!=null) mq.add(temp.right);
            }
            ans.add(temp1);
            
        }
        return ans;
    }
}