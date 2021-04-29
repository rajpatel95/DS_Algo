class Solution {
public:
    
    vector<string> ans;

    void dfs(string current, string digits, int index, vector<string>& table){
        
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        
        for(int i = 0; i < table[digit].size(); i++ ){
           
            current += table[digit][i];
            dfs(current, digits, index + 1, table);
            
            current.pop_back(); // BackTrack
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0){
            return ans;
        }
        
        vector<string> table(10);
        table[2] = "abc";
        table[3] = "def";
        table[4] = "ghi";
        table[5] = "jkl";
        table[6] = "mno";
        table[7] = "pqrs";
        table[8] = "tuv";
        table[9] = "wxyz";
        
    
        dfs("", digits, 0, table);
    
        return ans;
    }
    
};
