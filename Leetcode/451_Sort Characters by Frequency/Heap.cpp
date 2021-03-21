class Solution {
public:
    
    // Use Heap
    
    typedef struct Character{
        char c;
        int freq;
    };
    
    struct CompareFreq { 
        bool operator()(Character const& c1, Character const& c2){ 
            return c1.freq < c2.freq; 
        } 
    }; 
    
    string frequencySort(string s) {
        string ans;
        unordered_map<char, Character> mp;
        priority_queue<Character, vector<Character>, CompareFreq> heap;
        
        for( char c : s){
            if(mp.find(c) == mp.end()){
                Character character;
                character.c = c;
                character.freq = 1;
                mp[c] = character;
            } 
            else{
                mp[c].freq++;
            }
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            heap.push(it->second);
        }
        
        int i = 0;
        while(i < s.size()){
            Character character = heap.top();
            heap.pop();
            
            for(int j = 0 ; j < character.freq; j++ ){
                ans += character.c;
                i++;
            }
        }
        
        return ans;
        
    }
};
