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
    bool dede(TreeNode* root,long maxi,long mini){
        if(root==nullptr) return true;
        
        if(root->val>=maxi or root->val<=mini) return false;
        
        bool lef = dede(root->left,root->val,mini);
        bool righ = dede(root->right,maxi,root->val);
        return lef and righ;
    }
    bool isValidBST(TreeNode* root) {
        return dede(root,1e10,-1e10);
    }
};