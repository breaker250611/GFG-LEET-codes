/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    vector<TreeNode*>path;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans = vector<int>();
        path = vector<TreeNode*>();
        find(root,target);
        TreeNode* block = NULL;
        for(int i = 0;i<path.size();i++){
            klevel(path[i],k-i,block);
            block = path[i];
        }
        return ans;
    }
    void klevel(TreeNode*root,int k,TreeNode* block){
        if(root==NULL or k<0 or block == root )return ;
        if(k==0){
            ans.push_back(root->val);
        }
        
        klevel(root->left,k-1,block);
        klevel(root->right,k-1,block);
        return;
    }
    bool find(TreeNode*root,TreeNode* target){
        if(root==NULL){
            return false;
        }
        if(root==target){
            path.push_back(root);
            return true;
        }
        bool lef = find(root->left,target);
        bool righ = find(root->right,target);
        if(lef or righ){
            path.push_back(root);
            return true;
        }
        return false;
    }
};