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
    
    // Level order traversal and enter value of every element in the Stack and pop once

    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        stack<int> st;
        
        if( root == NULL ){
            return ans;
        }
        
        q.push(root);

        int level_size = 1; // Initial level size is 1 for the root node
        while( !q.empty() ){
            
            for( int i = 0 ; i < level_size ; i++ ){
                TreeNode* temp = q.front();
                q.pop();

                st.push(temp->val);

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if( temp->right != NULL ){
                    q.push(temp->right);
                }
            }

            ans.push_back(st.top());

            level_size = q.size(); // Number of elements inserted in the queue to process for next level
        }

        return ans;
    }
};
