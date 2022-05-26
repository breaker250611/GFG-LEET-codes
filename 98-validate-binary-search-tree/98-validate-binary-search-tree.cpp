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
    bool prefi(TreeNode* root,long long mini,long long  maxi){
        if(root==nullptr) return true;
        int lef = prefi(root->left,mini,root->val);
        if(lef==false) return false;
        int righ = prefi(root->right,root->val,maxi);
        return (root->val>mini && root->val<maxi && lef && righ);
   
    }
    bool isValidBST(TreeNode* root) {
      bool ans =   prefi(root,-1e10,1e10);
        return ans;
    }
};