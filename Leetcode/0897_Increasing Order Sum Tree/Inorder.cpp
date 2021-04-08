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
    
    TreeNode* tree;
    
    void inorder(TreeNode* node){
        if(node == NULL){
            return;
        }
        
        inorder(node->left);
        
        TreeNode *newNode = new TreeNode(node->val);
        tree->right = newNode;
        tree = tree->right;
        
        inorder(node->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans;
        tree = new TreeNode();
        ans = tree;
        inorder(root);
        return ans->right;
    }
};
