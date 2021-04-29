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

    void traverse(TreeNode* node, vector<int>& temp, int remainingSum, vector<vector<int>>& ans){
        if(node == NULL){
            return;
        }
        
        temp.push_back(node->val);
        if(remainingSum == node->val && node->left == NULL && node->right == NULL){
            ans.push_back(temp);
        }
        else{
            traverse(node->left, temp, remainingSum - node->val, ans);
            traverse(node->right, temp, remainingSum - node->val, ans);
        }
        
        temp.pop_back(); // BackTrack
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        traverse(root, temp, sum, ans);
        return ans;
    }
};
