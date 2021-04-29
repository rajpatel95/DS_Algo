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
    
    void inorder(TreeNode* node, TreeNode* p, vector<TreeNode*>& v){
        if(node == NULL){
            return;
        }
        
        inorder(node->left, p, v);
        
        v.push_back(node);
        
        inorder(node->right, p, v);
        
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;
        inorder(root, p, v);
        
        for(int i = 0 ; i < v.size() - 1; i++){
            if(v[i] == p ){
                return v[i + 1];
            }
        }
        return NULL;
    }
};
