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
    
    int sum;
    
    void dfs(TreeNode* node, int curr_sum){
        if(node->left == NULL && node->right == NULL ){
            sum += curr_sum * 10 + node->val;
            return;
        }
        if(node->left != NULL){
            dfs(node->left, curr_sum * 10 + node->val);
        }
        if(node->right != NULL){
            dfs(node->right, curr_sum * 10 + node->val);
        }
        
        
    }
    
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
};
