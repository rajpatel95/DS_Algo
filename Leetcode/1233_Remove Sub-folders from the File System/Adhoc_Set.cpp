class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        
        set<string> s;
        sort(folder.begin(), folder.end());
        
        for(string x: folder){
            string temp = "";
            
            for(int i = 0 ; i < x.size(); i++ ){
                if(x[i] == '/'){
                    temp += x[i];
                }
                else{
                    temp += x[i];
                    
                    if(s.find(temp) != s.end() && i < x.size() - 1 && x[i + 1] == '/' ){
                        break;
                    }
                    
                }
            }
            s.insert(temp);
        }
        
        for( auto it = s.begin(); it != s.end(); it++ ){
            ans.push_back(*it);
        }
        
        return ans;
    }
};
