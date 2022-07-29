/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int func(TreeNode*root){

        if (!root) return 0;
        
        int left = func(root->left);
        int right = func(root->right);
        
        ans += abs(left) + abs(right);
    
        return (root->val + left + right - 1);
    }
    
    int distributeCoins(TreeNode* root) {
        func(root);
        return ans;    
    }
};