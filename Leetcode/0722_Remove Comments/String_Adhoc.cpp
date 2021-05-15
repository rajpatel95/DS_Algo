class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool is_multicomment = false;
        string temp = "";
        
        
        
        for( string x: source ){
            
            for( int i = 0 ; i < x.size(); i++ ){
                if( !is_multicomment && x[i] == '/' && i < x.size() - 1 && x[i + 1] == '/'){
                    break;
                }
                else if( !is_multicomment && x[i] == '/' && i < x.size() - 1 && x[i + 1] == '*'){
                    is_multicomment = true;
                    i++;
                }
                else if( is_multicomment && x[i] == '*' && i < x.size() - 1 && x[i + 1] == '/'){
                    is_multicomment = false;
                    i++;
                }
                else if( !is_multicomment ){
                    temp += x[i];
                }
    
            }
            if( temp != "" && !is_multicomment){
                ans.push_back(temp);
                temp = "";
            }
            else if( !is_multicomment ){
                temp = "";
            }
            
        }
        
        return ans;
    }
};
