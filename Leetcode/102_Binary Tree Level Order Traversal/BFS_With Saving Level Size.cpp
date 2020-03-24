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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if( root == NULL ){
            return ans;
        }        
        queue<TreeNode*> q;
        q.push(root);
        
        int level_size = 1;
        while( !q.empty() ){
            vector<int> intermediate;
            
            // For a particular level enter all elements of that Level
            for( int i = 0 ; i < level_size ; i++ ){
                TreeNode* temp = q.front();
                q.pop();
                intermediate.push_back(temp->val);
                
                if( temp -> left != NULL ){
                    q.push(temp->left);
                }
                if(temp -> right != NULL ){
                    q.push( temp->right );
                }
            }
            ans.push_back(intermediate);
            level_size = q.size(); // Size of the next level

            
        }
        
        
        
        return ans;
    }
};
