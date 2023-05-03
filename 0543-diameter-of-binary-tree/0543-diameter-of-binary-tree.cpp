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
    int dia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        call(root);
        
        return dia;
    }
    
    
    int call(TreeNode* root){
        if(root==NULL) return 0;
        
        
        int lef = call(root->left);
        int righ = call(root->right);
        
        
        dia  = max(dia,lef+righ);
        
        return max(lef,righ)+1;
    }
};