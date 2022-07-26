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
    int widthOfBinaryTree(TreeNode* root) {
        if(root ==NULL) return 0;
        int ans = 1;
        queue<pair<TreeNode* , int>>q;
        q.push({root,1});
        while(!q.empty()){
            int sz = q.size();
            int mn = INT_MAX;
            int mx = INT_MIN;
            int sm = q.front().second;
            while(sz--){
                TreeNode* root = q.front().first;
                int idx = q.front().second;
                q.pop();
                mn  = min(mn,(idx-sm));
                mx = max(mx,(idx-sm));
                if(root->left) q.push({root->left,(long)2*(idx-sm)+1});
            if(root->right)q.push({root->right,(long)2*(idx-sm)+2});
            }
        ans = max(ans,mx-mn+1);
        }
    return ans;
    }
};