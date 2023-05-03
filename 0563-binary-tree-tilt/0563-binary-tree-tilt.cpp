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
    int findTilt(TreeNode* root) {
        ans = 0;
        
        call(root);
        return ans;
    }
    
    
    int call(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lef = call(root->left);
        int righ = call(root->right);
        
        ans += abs(lef-righ);
        
        return root->val+lef+righ;
    }
};