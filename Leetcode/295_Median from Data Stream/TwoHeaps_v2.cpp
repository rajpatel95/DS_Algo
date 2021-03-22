class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<double> max_heap;
    priority_queue<double> min_heap;
    
    int size;
    
    MedianFinder() {
        size = 0;
    }
    
    // Here, as all values are double, we can implement Min Heap as inserting negative values for proper implementation
    void addNum(int num) {
        if(size == 0){
            max_heap.push(num);
            size++;
            return;
        }
        
        if(max_heap.size() == min_heap.size()){
            if(num < max_heap.top()){
                max_heap.push(num);
            }
            else{
                //cout<<"Pushed in MIN : "<<num<<endl;
                min_heap.push(-num);
            }
        }
        else if(max_heap.size() > min_heap.size()){
            if(num < max_heap.top()){
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(-temp);
           
                    max_heap.push(num);
                }
                else{
                    min_heap.push(-num);
                }
            }
            else{
                if(num > -min_heap.top()){
                    int temp = -min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                  
                    min_heap.push(-num);
                }
                else{
                    max_heap.push(num);
                }
            }
            
        size++;
    }
        
    
    double findMedian() {
        
        if(size == 1){
            return max_heap.top();
        }
        
        double maxi = max_heap.top();
        double mini = -min_heap.top();
        double median;
        
        if(size % 2 == 0){
            median = (maxi + mini)/2;
        }
        else{
            if(min_heap.size() > max_heap.size()){
                median = mini;
            }
            else{
                median = maxi;
            }
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
