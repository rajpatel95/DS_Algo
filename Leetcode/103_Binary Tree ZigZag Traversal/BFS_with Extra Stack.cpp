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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        int level_size = 1;
        
        while( !q.empty() ){
            stack<int> st;
            
            vector<int> l_nodes;
            
            for(int i = 0 ; i < level_size ; i++ ){
                TreeNode* temp = q.front();
                q.pop();
                
                if( level % 2 != 0){
                    st.push(temp->val);
                }
                else{
                    l_nodes.push_back(temp->val);
                }
                if( temp->left != NULL ){
                    q.push(temp->left);
                }
                if( temp->right != NULL ){
                    q.push(temp->right);
                }
            }
            if( level % 2 != 0 ){
                while(!st.empty()){
                    l_nodes.push_back(st.top());
                    st.pop();
                }
                
            }
            ans.push_back(l_nodes);
            level_size = q.size(); // Maintains Number of nodes in the next level
            level++; // Maintain nth level number for odd-even level
        }
        
        return ans;
    }
};
