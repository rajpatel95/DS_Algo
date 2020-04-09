class Solution {
public:
    
    // Similar to Solution 1, Sort strings and make groups of sorted strings
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        // unordered map for faster access as sequence is not an issue here
        unordered_map<string, vector<string>> mp;
        
        for( string s : strs ){
            string temp = s; // Store temporary Value of the string to enter in the map
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        
        // Traversing  a Map by auto
        for( auto pp : mp ){
            ans.push_back(pp.second); // Enter every grouped array of anagramed strings
        }
        
        return ans;
        
    }
};
