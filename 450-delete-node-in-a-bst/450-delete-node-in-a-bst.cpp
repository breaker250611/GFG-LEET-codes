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
    
    void attach (TreeNode *l , TreeNode *r){
       while (r and r->left){
           r = r->left;
       }  
       r->left = l;
    }
    
    TreeNode *createandsearch(TreeNode *root , int key){
        
        if (!root) return NULL;
        if (root->val == key){
            if (!root->right) return root->left;
            attach(root->left , root->right);
            return root->right;
        }
        
        if (key > root->val)
         root->right = createandsearch(root->right , key);
        if (key < root->val)
         root->left = createandsearch(root->left , key);
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
       return createandsearch(root , key);
    }
};