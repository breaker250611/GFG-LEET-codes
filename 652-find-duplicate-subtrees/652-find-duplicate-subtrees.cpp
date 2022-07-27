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
vector<TreeNode*> ans;
map<string,int>mp;
    string postorder(TreeNode* root){
        // L R N
        
        if(root==NULL) return "#";
        
        
        string str  =  postorder(root->left) + ","+ postorder(root->right)+ "," + to_string(root->val);
        
        if(mp.find(str)!=mp.end()){
            if(mp[str]==1){
                ans.push_back(root);
            }
        }
        mp[str]++;
        return str;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ans.clear();
        mp.clear();
        postorder(root);
        return ans;
    }
};