class KthLargest {
public:
    
    typedef struct MinHeap{
        bool operator()(int const& i1, int const& i2){
            return i1 > i2;
        }  
    };

    priority_queue<int, vector<int>, MinHeap> min_heap;
    int kth;
    
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        
        if(nums.size() == 0){
            return;
        }
        
        for(int i = 0; i < nums.size(); i++ ){
            
            if( i >= k ){
                
                if(nums[i] > min_heap.top()){
                    min_heap.pop();
                
                    min_heap.push(nums[i]);
                }
                
            }
            else{
                min_heap.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {
        
        if( min_heap.size() < kth ){
            min_heap.push(val);
        }
        else if( val > min_heap.top() ){
            min_heap.pop();
        
            min_heap.push(val);
        }
        
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
