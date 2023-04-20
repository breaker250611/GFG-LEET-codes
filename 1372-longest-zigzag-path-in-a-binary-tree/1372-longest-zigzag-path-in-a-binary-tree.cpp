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
    // 0 -> left
    // 1 -> right
    // 2 -> root
    int ans = 0;
    void call(TreeNode* root,int val, int sum){
        ans = max(ans,sum);  
        if(root==NULL){
                
                return ;
            }
        if(val==2){
            if(root->left ){
                call(root->left,0,sum+1);
            }
            if(root->right){
                call(root->right,1,sum+1);
            }
        }
        if(val==0){
            if(root->left){
                call(root->left,0,1);
            }
            if(root->right){
                call(root->right,1,sum+1);
            }
        }
        if(val==1){
            if(root->left){
                call(root->left,0,sum+1);
            }
            if(root->right){
                call(root->right,1,1);
            }
        }
    }
    
    int longestZigZag(TreeNode* root) {
        call(root,2,0);
        return ans;
    }
};