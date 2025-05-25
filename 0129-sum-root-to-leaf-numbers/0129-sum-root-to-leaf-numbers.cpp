class Solution {
public:
    int dfs(TreeNode* node, int pathSum){
        if(node==NULL) return 0;
        
        pathSum= pathSum*10 + node->val;
        
        if(!node->left && !node->right) return pathSum;
        
        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};