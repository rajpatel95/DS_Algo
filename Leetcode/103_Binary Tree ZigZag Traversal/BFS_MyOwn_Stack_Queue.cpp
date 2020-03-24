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
    
     typedef struct myqueue{
         TreeNode* queue[100001];
         int front,rear;
         
         myqueue(){
             front = 0;
             rear = -1;
         }
         
         void enqueue(TreeNode* node){
             queue[++rear] = node;
         }
         
         TreeNode* dequeue(){
             return queue[front++];
         }
         
         bool isEmpty(){
             if( front > rear ){
                 return true;
             }
             return false;
         }
         
         int size(){
             return rear - front + 1;
         }
        
    };
    
     typedef struct mystack{
        int stack[100001];
        int tos;
        
        mystack(){
            tos = -1;
        }
        
        int pop(){
            return stack[tos--];
        }
        
        bool isEmpty(){
            if( tos < 0 ){
                return true;
            }
            return false;
        }
        
        void push( int x ){
            stack[++tos] = x;
        }
        
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
       
        myqueue q = myqueue();
        
        q.enqueue(root);
        int level = 0;
        int level_size = 1;
        
        while(!q.isEmpty()){
            
            mystack st = mystack();
             
            vector<int> l_nodes;
            
            for( int i = 0 ; i < level_size ; i++ ){
                TreeNode* temp = q.dequeue();
                
                if(level % 2 != 0){
                    st.push(temp->val);
                }
                else{
                    l_nodes.push_back(temp->val);
                }
                
                if( temp->left != NULL ){
                    q.enqueue(temp->left);
                }
                if( temp->right != NULL ){
                    q.enqueue(temp->right);
                }
            }
            
           if( level % 2 != 0 ){
                while(!st.isEmpty()){
                    l_nodes.push_back(st.pop());
                }
                
            }
            ans.push_back(l_nodes);
            level_size = q.size();
            level++;
            
        }
        
        
        return ans;
    }
};
