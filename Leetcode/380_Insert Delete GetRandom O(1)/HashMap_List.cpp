class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> mp; // Map that stores the number and it's index in the list
    vector<int> elements; // For Random return operation
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = mp.find(val);
        if( it != mp.end() ){
            return false;
        }
        mp.insert( {val, elements.size()} );
        elements.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);
        if( it == mp.end() ){
            return false;
        }
        int last_index = elements.size()-1;
        int element_index = mp[val];
        if( last_index == element_index){
            mp.erase(val);
            elements.pop_back();
            return true;
        }
        swap(elements[element_index], elements[last_index]);
        mp.erase(val);
        elements.pop_back();
        mp[elements[element_index]] = element_index;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % elements.size();
        return elements[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
