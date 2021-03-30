class Solution {
public:
    
    // Look at the operations that can be performed carefully and see that, we can't just sum of differences, we need to 
    // completely swap the elements, so frequencies at max. could be swapped
    
    bool closeStrings(string word1, string word2) {
        vector<int> hash_1(26, 0), hash_2(26, 0);
        set<char> s1, s2;
        
        if(word1.size() != word2.size()){
            return false;
        }
      
        int size = word1.size();
        for(int i = 0 ; i < size; i++ ){
            hash_1[word1[i] - 'a']++;
            s1.insert(word1[i] - 'a');
            hash_2[word2[i] - 'a']++;
            s2.insert(word2[i] - 'a');
        }
        
        sort(hash_1.begin(), hash_1.end());
        sort(hash_2.begin(), hash_2.end());
        
        
        return (hash_1 == hash_2) && (s1 == s2);
    }
};
