class Solution {
public:
    // Naive aApproach, will give TLE for large strings, Use Sliding Window technique instead
    
    bool checkAnagram(string a, string b){
        if( a.length() != b.length() ){
            return false;
        }
        
        int table[26];
        
        for( int i = 0 ; i < 26 ; i++ ){
            table[i] = 0;
        }
        
        for( int i = 0 ; i < a.length() ; i++ ){
            table[a[i] - 'a']++;
            table[b[i] - 'a']--;
        }
        
        for( int i = 0 ; i < 26 ; i++ ){
            if( table[i] != 0 ){
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if( s == "" || p == "" || p.length() > s.length() ){
            return ans;
        }
        
        for( int i = 0 ; i < s.length() ; i++ ){
            if( i + p.length() > s.length() ){
                break;
            }
            string a = s.substr(i, p.length());
            string b = p;
            //cout<<a<<":"<<b<<endl;
            
            if( checkAnagram(a, b) ){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
