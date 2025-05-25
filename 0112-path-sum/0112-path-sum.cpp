class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;

        if (!root->left && !root->right){
            if(targetSum-root->val==0) return true;
        }

        targetSum-=root->val;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);        
    }
};