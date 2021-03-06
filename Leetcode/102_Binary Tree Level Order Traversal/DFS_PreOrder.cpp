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
    
    vector<vector<int>> ans;
    int max_level;
    
    void dfsLevelOrder(TreeNode* node, int level){
        if( node == NULL ){
            return;
        }
        if( level <= max_level ){
            ans[level].push_back(node->val);
        }
        else{
            vector<int> temp;
            temp.push_back(node->val);
            ans.push_back(temp);
            max_level++;
        }
        
        dfsLevelOrder(node->left, level + 1);
        dfsLevelOrder(node->right, level + 1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
      
        if(root == NULL){
            return ans;
        }
      
        max_level = 0;
        vector<int> temp;
        ans.push_back(temp);
      
        dfsLevelOrder(root, 0);
        return ans;
    }
};
