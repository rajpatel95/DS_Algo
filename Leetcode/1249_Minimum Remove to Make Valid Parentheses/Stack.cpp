class Solution {
public:
    
    // To keep track of Open paranthesis
    typedef struct stackNode{
        char open_paran;
        int pos;
        
        stackNode( char c, int n){
            open_paran = c;
            pos = n;
        }
    };
    
    string minRemoveToMakeValid(string s) {
        string ans = "";
        vector<char> temp;
        stack<stackNode> st; 
        
        for( char c : s ){
            if( c == '('){
                stackNode new_node = stackNode('(', temp.size());
                st.push(new_node);
                temp.push_back(c);
            }
            else if( c == ')'){
                if( !st.empty() ){
                    st.pop();
                    temp.push_back(c);
                }
            }
            else{
                temp.push_back(c);
            }
        }
        
        // Remove extra open paranthesis
        while( !st.empty() ){
            int idx = st.top().pos;
            temp.erase(temp.begin() + idx); // to convert into const_iterator
            st.pop();
        }
        
        for( char c : temp ){
            ans += c;
        }
        
        return ans;
    }
};
