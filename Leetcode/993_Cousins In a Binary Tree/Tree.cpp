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
private:
    
   int calcHeight(TreeNode *node, int target, int cnt ){
        
        if( node == NULL ){
            return 0;
        }
        if( node->val == target ){
            return cnt;
        }
        
        return max(calcHeight(node->left, target, cnt + 1), calcHeight(node->right, target, cnt + 1));
    }
    
    int returnParent(TreeNode *node, int child){
        if( node == NULL ){
            return -1;
        }
        
        if( node->left != NULL && node->left->val == child ){
            return node->val;
        }
        if( node->right != NULL && node->right->val == child ){
            return node->val;
        }
        return max(returnParent(node->left, child), returnParent(node->right, child));
    }
    
public:
 
    bool isCousins(TreeNode* root, int x, int y) {
        
        if( calcHeight(root, x, 0) != calcHeight(root, y, 0) ){
            return false;
        }
        if( returnParent(root, x) == returnParent(root, y) ){
            return false;
        }
        
        return true;
    }
};
