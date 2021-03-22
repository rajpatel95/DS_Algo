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
    
    int ans;
    
    void traverse(TreeNode* node, int L, int R){
        if( node == NULL){
            return;
        }
        
        if( node->val >= L && node->val <= R ){
            ans += node->val;
        }
        if( node->val >= L ){
            traverse(node->left, L, R);
        }
        if( node->val <= R){
            traverse(node->right, L, R);
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        ans = 0;
        traverse(root, L, R);
        return ans;
    }
};
