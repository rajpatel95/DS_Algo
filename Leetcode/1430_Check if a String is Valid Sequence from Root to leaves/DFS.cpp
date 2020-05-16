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
    
    bool dfs(TreeNode* node, int cnt, vector<int>& arr){
        if( node == NULL){
            return false;
        }
        if( node->left == NULL && node->right == NULL ){
            if( cnt == arr.size() - 1 && node->val == arr[cnt] ){
               return true;
            }
            return false;
        }
        if( cnt >= arr.size() || node->val != arr[cnt] ){
            return false;
        }
        return dfs(node->left, cnt + 1, arr) || dfs(node->right, cnt + 1, arr);
        
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, 0, arr);
    }
};
