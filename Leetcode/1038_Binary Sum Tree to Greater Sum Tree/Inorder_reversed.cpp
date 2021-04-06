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
    
    void reverse_inorder(TreeNode* Node){
        if( Node == NULL){
            return;
        }
        
        reverse_inorder(Node->right);
        
        sum += Node->val;
        Node->val = sum;
        
        
        reverse_inorder(Node->left);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        reverse_inorder(root);

        return root;
    }
};
