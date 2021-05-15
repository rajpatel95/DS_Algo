class Solution {
public:
    
    vector<string> oneMove(string source, set<string>& s, set<string>& visited){
        vector<string> destinations;
        
        for(int i = 0 ; i < 4 ; i++ ){
            string temp = source;
            
            if( source[i] == '9'){
                temp[i] = '0';
            }
            else{
                temp[i] += 1;
            }
            
            if( (s.find(temp) == s.end()) && (visited.find(temp) == visited.end()) ){
                destinations.push_back(temp);
                visited.insert(temp);
            }
            
            temp = source;
            
            if( source[i] == '0'){
                temp[i] = '9';
            }
            else{
                temp[i] -= 1;
            }
            
            if( (s.find(temp) == s.end()) && (visited.find(temp) == visited.end()) ){
                destinations.push_back(temp);
                visited.insert(temp);
            }
            
        }
        
        return destinations;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> s,visited;
        int ans = 0;
        queue<string> q;
        q.push("0000");
      
        for( string x: deadends){
            s.insert(x);
        }
        
        // Special case
        if( s.find("0000") != s.end() ){
            return -1;
        }
        
        while( !q.empty() ){
            int q_size = q.size();
            
            while( q_size-- ){
                string str = q.front();
                q.pop();
                
                if( str == target ){
                    return ans;
                }
                
                vector<string> allcombinations = oneMove(str, s, visited);
                
                for( string x: allcombinations ){
                   q.push(x);
                }
            }
            ans++;
        }
        
        return -1;
        
    }
};
