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
    struct data{
        int min;
        int max;
        int sum;
        bool poss;
    };
    int maxi = 0;
    
    data call(TreeNode* root){
        if(root==NULL){
            struct data s;
            s.min = INT_MAX;
            s.max = INT_MIN;
            s.sum = 0;
            s.poss = true;
            return s;
        }
        if(root->right==nullptr and root->left == nullptr){
            struct data bhej;
            bhej.min = root->val;
            bhej.max = bhej.min;
            bhej.sum = bhej.max;
            bhej.poss = true;
            maxi = max(bhej.sum,maxi);
            return bhej;
        }
        struct data left = call(root->left);
        struct data right = call(root->right);
        int valu = root->val;
        if(left.poss==false)return left;
        if(right.poss==false)return right;
        if(valu>left.max and valu<right.min){
            struct data naya;
            // cout<<left.max<<" ";
            // cout<<right.min<<endl;
            naya.min = min(left.min,root->val);
            naya.max = max(right.max,root->val);
            // cout<<naya.min<<endl;
            naya.sum = left.sum+right.sum+valu;
            naya.poss= true;
            maxi = max(naya.sum,maxi);
            // cout<<maxi<<endl;
            return naya;
        }
        else{
            left.poss = false;
                return left;
        }
        
    }
    
    
    int maxSumBST(TreeNode* root) {
        maxi = 0;
        data ans = call(root);
        maxi = max(ans.sum,maxi);
        return maxi;
        
    }
};