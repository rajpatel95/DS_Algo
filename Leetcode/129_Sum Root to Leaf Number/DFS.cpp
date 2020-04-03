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
    
    // Idea is to keep on multiplying every intermediate sum by 10, until the leaf Node is reached
    int dfs( TreeNode* temp, int sum){
        
        // NULL node
        if( temp == NULL ){
            return 0;
        }
        
        // Leaf Node reached, Add it's value as Unit's place and add to the sum
        if( temp-> right == NULL && temp->left == NULL ){
            return sum*10 + temp->val;
        }
        
        return dfs(temp->left, sum*10 + temp->val ) + dfs(temp->right, sum*10 + temp->val);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
