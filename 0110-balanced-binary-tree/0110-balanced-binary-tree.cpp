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
    bool isBalanced(TreeNode* root) {
        int ans = call(root);
        
        if(ans==-1)return false;
        return true;
    }
    
    
    
    int call(TreeNode* root){
        if(root==NULL)return 0;
        
        int lef = call(root->left);
        int righ = call(root->right);
        
        if(lef == -1 or righ == -1 or abs(lef-righ)>1) return -1;
        
        return max(lef,righ)+1;
    }
        
};