class Solution {
public:
    
    // Naive Solution, without using HashMap, will give TLE for large sized strings
    
    int checkGroup(vector<vector<int>>& parents, vector<int>& child){
        
        for( int i = 0 ; i < parents.size() ; i++ ){
            if(parents[i] == child){
                return i;
            }
        }
        
        return -1;
    }
    
    vector<int> makeTable(string s){
        vector<int> temp;
        for( int i = 0 ; i < 26 ; i++){
            temp.push_back(0);
        }
        for( int i = 0 ; i < s.size() ; i++ ){
            temp[s[i] - 'a']++;
        }
        
        return temp;
    }
    
    string makeString( string s ){
        string 
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        if( strs.size() == 0 ){
            return ans;
        }
        
        vector<vector<int>> tables; // Containing group by character count, optimized way is to use Hashmap
        map<string, int> mp; // String is vectored hashtable, while int is the index
        
        tables.push_back(makeTable(strs[0]));
        vector<string>temp2 ;
        temp2.push_back("");
        ans.push_back(temp2);
        ans[0][0] = strs[0];
        
        for( int i = 1 ; i < strs.size() ; i++ ){
            vector<int> temp = makeTable(strs[i]);
            int index = checkGroup(tables, temp);
            if( index != -1 ){
                ans[index].push_back(strs[i]);
                continue;
            }
            vector<string> temp1;
            temp1.push_back("");
            ans.push_back(temp1);
            ans[ans.size()-1][0] = strs[i];
            tables.push_back(temp);
        }
        
        return ans;
        
    }
};
