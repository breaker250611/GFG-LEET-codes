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
    vector<int> ans;    
    bool func(TreeNode *root , TreeNode *target , vector<TreeNode*>&ar ){
        
        if (!root)
            return false;
        if (root == target){
            ar.push_back(root);
            return true;
        }
        
        ar.push_back(root);
        bool left = func(root->left , target , ar);
        bool right = func(root->right , target , ar);
        
        if (!left and !right){
            ar.pop_back();
            return false;
        }
        return true;    
    }
    
    void calc(TreeNode* root , int k , TreeNode* blocked){
        
        if (!root or root == blocked) return;
        if (k == 0){ans.push_back(root->val); return;}
        calc(root->left , k-1 , blocked);
        calc(root->right, k-1 , blocked);
        
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        ans.clear();
        vector<TreeNode*> ar;
        func(root , target , ar);
        reverse(ar.begin() , ar.end());
        // for (auto x : ar)
        //     cout << x->val << '\n';
        for (int i = 0 ; i <= min(k , (int) ar.size()-1) ; i++){
             calc(ar[i] , k-i , (i == 0 ? NULL : ar[i-1]));  
        } 
        
        return ans;
    }
};