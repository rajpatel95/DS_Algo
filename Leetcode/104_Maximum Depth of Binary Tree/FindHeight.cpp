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
    
    int findHeight(TreeNode* node){
        if( node == NULL ){
            return 0;
        }
        
        int l = 1 + findHeight(node->left);
        int r = 1 + findHeight(node->right);
        
        return max(l,r);
    }
    
    int maxDepth(TreeNode* root) {
        return findHeight(root);
    }
};
