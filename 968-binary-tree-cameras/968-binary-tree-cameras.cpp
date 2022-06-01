class Solution {
public:
    // 1 -> i required a camera ..
    // 0 -> i dont not require a camera..
    // 2 -> i have a camera ..child has a camera installed .. 
    int cameras;
    int func(TreeNode *root){
        
        if (!root)
            return 0;
        if (root->left == NULL and root->right == NULL)
            return 1;
        
        
       int left =  func(root->left);
       int right = func(root->right);
        
        if (left == 1 or right == 1){
            cameras++;
            return 2;
        }
        
        if (left == 0 and right == 0){
          return 1;   
        }
        if (left == 2 or right == 2)
            return 0;
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        int val = func(root);
        if (val == 1) cameras++;
        return cameras;
    }
};