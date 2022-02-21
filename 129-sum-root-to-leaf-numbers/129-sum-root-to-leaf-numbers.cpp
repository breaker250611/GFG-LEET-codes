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
    void preorder(TreeNode* root, string psf, vector<int>& s) {
            if(root==nullptr) return;

    if (root->left==nullptr&&root->right==nullptr) {
        //     cout<<psf<<endl;
        char ch = root->val+'0';
        psf+=ch;
        stringstream geek(psf);

        int x = 0;
        geek >> x;

        s.push_back(x);
        return;
    }
    char n = root->val + '0';
    preorder(root->left, psf + n, s);
    preorder(root->right, psf + n, s);
}
    int sumNumbers(TreeNode* root) {
        vector<int> s;
    preorder(root, "", s);
    for (auto x : s) cout << x<<endl;
    int ans = accumulate(s.begin(), s.end(), 0);
    return ans;
    }
};