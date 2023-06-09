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
    int sum = 0;
    
    
    void call(TreeNode* root){
        if(root==NULL)return ;
        
        call(root->right);
        root->val += sum;
        sum = root->val;
        call(root->left);
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        
        call(root);
        return root;
        
    }
};