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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==0){
            return {};
        }
        if(n==1){
            return {new TreeNode()};
        }
        
        vector<TreeNode*> res;
        for(int i = 1;i<n-1;i = i+2){
                
            vector<TreeNode*> lef = allPossibleFBT(i);
            vector<TreeNode*> righ = allPossibleFBT(n-i-1);
            
            
            
            for(auto&l:lef){
                for(auto&r:righ){
                    TreeNode* temp = new TreeNode(0,l,r);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};