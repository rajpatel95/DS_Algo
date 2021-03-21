class Solution {
public:
    
    typedef struct Element{
        int value;
        int freq;
    };
    
    typedef struct CompareFreq{
        bool operator()(Element const& e1, Element const& e2){
            return e1.freq < e2.freq;
        }  
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<Element, vector<Element>, CompareFreq> heap;
        unordered_map<int, Element> mp;
        
        for(int x: nums){
            if(mp.find(x) == mp.end()){
                Element et;
                et.value = x;
                et.freq = 1;
                mp[x] = et;
            }
            else{
                mp[x].freq++;
            }
        }
        
        for( auto it = mp.begin(); it != mp.end() ; it++ ){
            heap.push(it->second);
        }
        
        while( !heap.empty() && k-- ){
            Element et = heap.top();
            heap.pop();
            ans.push_back(et.value);
        }
        
        return ans;
    }
};
