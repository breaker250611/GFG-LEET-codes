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
    map<string , int> m;
    
    string func(TreeNode *root){
       
        if (!root){
            return "#";
        }
        
        string s = func(root->left) + "," + func(root->right) + "," + to_string(root->val);
        
        if (m.count(s)){
            if (m[s] == 1)
            ans.push_back(root);
        }
        m[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       string s;
       func(root);
       return ans;
    }
};