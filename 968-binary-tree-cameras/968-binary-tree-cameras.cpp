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
    #define NO_NEED 0
    #define NEED 1
    #define MONITORED 2
    int cameras = 0;
    int dfs(TreeNode * root) {
        if (root == nullptr) {
            return NO_NEED;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return NEED;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == NEED or right == NEED) {
            cameras ++; 
            return MONITORED;
        }
        
        if (left == MONITORED or right == MONITORED) {
            return NO_NEED;
        }
        
        if (left == NO_NEED && right == NO_NEED) {
            return NEED;
        }
        return -1e5;
    }
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        int temp = dfs(root);
        if (temp == NEED) {
            cameras ++;
        }
        return cameras;
    }
};