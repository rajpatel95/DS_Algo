class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> min_heap;
        
        for(int x: nums){
            if(min_heap.size() >= k){
                if( x > -min_heap.top()){
                    min_heap.pop();
                    min_heap.push(-x);
                }
            }
            else{
                min_heap.push(-x);
            }
        }
        
        return -min_heap.top();
    }
};
