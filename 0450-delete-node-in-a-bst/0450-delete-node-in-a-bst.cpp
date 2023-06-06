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
    
    
    TreeNode* call(TreeNode* root,int key){
        if(root==NULL)return root;
        
        if(root->val==key){
            if(root->right==NULL and root->left==NULL)return NULL;
            if(root->right==NULL)return root->left;
            else if(root->left==NULL)return root->right;
            else{
                
                TreeNode* temp = root->left;
                while(temp->right != nullptr){
                    temp = temp->right;
                }
                temp->right = root->right;
                return root->left;
            }
        }
            
        root->left = call(root->left,key);
        root->right = call(root->right,key);
        return root;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = call(root,key);
        return root;
    }
};