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
    int ans;
    vector<int> func(TreeNode *root , int dis){
    
        if (!root) {
            return {};
        }
        
        if (root->left == NULL and root->right == NULL)
            return {1};
        
        vector<int> left  = func(root->left , dis);
        vector<int> right = func(root->right , dis);
        
        vector<int> temp;
        
        for (int i = 0 ; i < left.size() ; i++){
            auto it = upper_bound(right.begin() , right.end() , dis-left[i])-right.begin();
            ans += it;
            temp.push_back(left[i]+1);
        }
        for (int j = 0 ; j < right.size() ; j++){
              temp.push_back(right[j]+1);
        }
        sort(temp.begin() , temp.end());
        return temp;
    }
    
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        func(root , distance);
        return ans;
    }
};