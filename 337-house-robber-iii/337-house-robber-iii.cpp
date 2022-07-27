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
struct Data{
    
    int lena;
    int nhilena;
    
    Data(int lena , int nhilena){
        this->lena = lena;
        this->nhilena = nhilena;
    }  
};
class Solution {
public:
    int ans;
    Data func(TreeNode *root){
        
        if (!root){
            return {0 , 0};
        }
        if (root->left == NULL and root->right == NULL)
        {
            ans = max(ans , root->val);
            return {root->val , 0};
        }
        
        Data left = func(root->left);
        Data right = func(root->right);
        
        Data curr(0 , 0);
        curr.lena = root->val + left.nhilena  + right.nhilena;
        curr.nhilena = max(left.lena , left.nhilena) + max(right.lena , right.nhilena);
        
        ans = max({ans , curr.lena , curr.nhilena});
        
        return curr;
    }
    
    int rob(TreeNode* root) {
        ans = 0;
        func(root);
        return ans;
    }
};