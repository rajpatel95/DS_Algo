class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash_a(26,0), hash_b(26,0);
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++ ){
            hash_a[s[i] - 'a']++;
            hash_b[t[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++ ){
            if(hash_b[i] > hash_a[i]){
                ans += hash_b[i] - hash_a[i];
            }
        }
        
        return ans;
        
    }
};
