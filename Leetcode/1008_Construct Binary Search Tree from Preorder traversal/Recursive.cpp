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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if( preorder.size() == 0 ){
            return NULL;
        }
        
        int root_value = preorder[0]; // First element will it's root
        vector<int> smaller, greater; // Vectors for pushing values smaller and greater than the root_value
        
        for( int i = 1 ; i < preorder.size() ; i++ ){
            if( preorder[i] > root_value ){
                greater.push_back(preorder[i]);
            }
            else{
                smaller.push_back(preorder[i]);
            }
        }
        
        TreeNode *root = new TreeNode(root_value);
        root->left = bstFromPreorder(smaller); // Recursive call for elements smaller than this
        root->right = bstFromPreorder(greater);
        
        return root;
        
    }
};
