class TimeMap {
public:
    /** Initialize your data structure here. */
    typedef struct MyPair{
        string value;
        int timestamp;
    };
    
    typedef struct ComPair{
        bool operator()(MyPair const& mp1, MyPair const& mp2){
            return mp1.timestamp < mp2.timestamp;
        }  
    };
    unordered_map<string, priority_queue<MyPair, vector<MyPair>, ComPair> > mp;
    
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        MyPair pair;
        pair.value = value;
        pair.timestamp = timestamp;
        mp[key].push(pair);
    }
    
    string get(string key, int timestamp) {
		
        if(mp.find(key) == mp.end()){
            return "";
        }
        string ans;
		
        vector<MyPair> temp;
        
        while( !mp[key].empty() ){
            
            MyPair pair = mp[key].top();
           
            if(pair.timestamp <= timestamp){
                ans = pair.value;
                break;
            }
            temp.push_back(pair);
            mp[key].pop();
        }
    
        
        for(int i = 0 ; i < temp.size(); i++ ){
            mp[key].push(temp[i]);
        }
        

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
