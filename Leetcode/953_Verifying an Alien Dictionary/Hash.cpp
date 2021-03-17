class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        
        for( int i = 0 ; i < 26 ; i++ ){
            mp.insert( {order[i], i} );
        }
        
        // Compare current and previous at a time, O(n * max(len(word))), n is number of words
        for( int i = 1 ; i < words.size() ; i++ ){
            string s1 = words[i-1];
            string s2 = words[i];
            for( int j = 0 ; j < words[i].size() ; j++ ){
                if( mp[s2[j]] < mp[s1[j]] ){
                    return false;
                }
                else if( mp[s2[j]] > mp[s1[j]] ){
                    break;
                }
                if( j == s1.size() - 1){
                    break;
                }
                else if( j == s2.size() - 1 ){
                    return false;
                }
            }
        }
        
        return true;
    }
};
