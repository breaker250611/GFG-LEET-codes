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
    int msum = 0;
    int postorder(TreeNode* root){
        if(root==nullptr ) return 0 ;
        
        int lef = postorder(root->left);
        int righ = postorder(root->right);
        
        if(lef==0 and righ==0) return 1;
        else if(lef != 0 and righ != 0 ){
            if(root->left->val==root->val and root->right->val == root->val){
                msum = max(lef + righ+1,msum);
                return max(lef,righ)+1;
            }
            else if(root->left->val == root->val) {msum = max(lef+1,msum) ; return lef+1;}
            else if(root->right->val == root->val) {msum = max(msum,righ+1);return righ+1;}
            else return 1;
            
        }
        else if(lef == 0){
                if(root->right->val == root->val) {msum = max(msum,righ+1);return righ+1;}
            else return 1;
            
        }
        else if(righ==0){
            if(root->left->val == root->val) {msum = max(lef+1,msum) ; return lef+1;}
            else return 1;
        }
        return msum;
        
    }
    int longestUnivaluePath(TreeNode* root) {
     if(root==nullptr)return 0;
        msum = 0;
        
        int x = postorder(root);
        // msum = max(x,msum);
        return msum = (msum>1)?msum-1:msum;
        
    }
};