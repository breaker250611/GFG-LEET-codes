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
    bool isCousins(TreeNode* root, int x, int y) {
        
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        
        
        while(!q.empty()){
            int n = q.size();
            count = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->val==x or temp->val == y){
                    count++;
                }
               if(temp->left and temp->right){
                    if(temp->left->val==x and temp->right->val==y){
                    return false;
                }
                else if(temp->right->val==x and temp->left->val==y){
                    return false;
                }
               }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            
            if(count == 2)return true;
        }
        
        
        
        
        
        
        
        
        
        
        return false;
    }
};