class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if( s == "" || p == "" || p.length() > s.length() ){
            return ans;
        }
        
        vector<int> ptable(26,0), stable(26,0);
        
        for( int i = 0 ; i < p.length() ; i++ ){
            ptable[p[i] - 'a']++;
            stable[s[i] - 'a']++;
        }
        
        for( int i = p.length() ; i < s.length() ; i++ ){
            
            if( stable == ptable ){
                ans.push_back(i - p.length());
            }
            
            stable[s[i - p.length()] - 'a']--;
            stable[s[i] - 'a']++;
        }
        
        if(stable == ptable){
            ans.push_back(s.length() - p.length());
        }
        
        return ans;
    }
};
