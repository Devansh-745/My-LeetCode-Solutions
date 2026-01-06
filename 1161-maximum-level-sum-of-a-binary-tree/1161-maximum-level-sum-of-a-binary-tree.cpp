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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxsum=INT_MIN;
        int ans=0;
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int cursum=0;
            for(int i=q.size(); i>0; i--){
                TreeNode* node=q.front();
                q.pop();
                cursum+=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(maxsum<cursum){
                maxsum=cursum;
                ans=level;
            }
        }
        return ans;
    }
};