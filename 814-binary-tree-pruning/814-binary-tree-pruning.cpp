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
    int preorder(TreeNode* root){
        if(root==nullptr) return 0;
        
        int lef = preorder(root->left);
        int righ = preorder(root->right);
        
        if(lef==0) root->left = nullptr;
        if(righ==0) root->right = nullptr;
        int ans = lef or righ;
        return (root->val or ans);
    }
    TreeNode* pruneTree(TreeNode* root) {
        int ans = preorder(root);
        return  (ans==0)?nullptr:root;
    }
};