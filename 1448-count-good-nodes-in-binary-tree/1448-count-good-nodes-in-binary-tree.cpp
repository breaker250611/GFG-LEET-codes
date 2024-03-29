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
    int count = 0;
    void prefix(TreeNode* root,int maxi){
        if(root==NULL)return;
        if(root->val>=maxi)count++;
        maxi = max(maxi,root->val);
        prefix(root->left,maxi);
        prefix(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        count = 0;
        prefix(root,INT_MIN);
        return count;
    }
};