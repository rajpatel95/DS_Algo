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
        
    vector<int> largestValues(TreeNode* root) {
        // Perform Level-Order Traversal by using BFS and store maximum of every level
        
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        

        int level_size = 1; // Maintain number of Non-null nodes in the current level
        
        while( !q.empty() ){
            
            int maxi = INT_MIN;
            
            // Traverse for all Non-null Nodes of the current Level
            for( int i = 0 ; i < level_size ; i++ ){
                            
                // Store the Front in a Node and then Dequeue the Node
                TreeNode* temp = q.front();
                q.pop();

                if( maxi <= temp->val ){
                    maxi = temp->val;
                }

                if(temp->left != NULL){
                    q.push(temp->left);
                }

                if(temp->right != NULL){
                    q.push(temp->right);
                }
                
            }
            ans.push_back(maxi);
            level_size = q.size();
            
        }
        
        return ans;
    }
};
