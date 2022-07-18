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
    int maxi = 0;
    int check(TreeNode* root){
        if(root==nullptr) return 0;
        
        int lef = check(root->left);
        int rig = check(root->right);
        int fin_lef = 0;
        int fin_rig = 0;
        if(lef!=0 and root->val==root->left->val){
            fin_lef = lef;
        }
        if(rig!=0 and root->val==root->right->val){
            fin_rig = rig;
        }
        maxi = max(maxi,fin_lef+fin_rig);
        return max(fin_lef,fin_rig)+1;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;
        check(root);
        return maxi;
    }
};