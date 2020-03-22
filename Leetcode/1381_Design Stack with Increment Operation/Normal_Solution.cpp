class CustomStack {
public:
    
    int arr[10000];
    int maxi;
    int tos = -1;
    
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if (tos < maxi - 1){
            arr[++tos] = x;   
        }
    }
    
    int pop() {
        if( tos == -1 ){
            return -1;
        }
        return arr[tos--];
    }
    
    void increment(int k, int val) {
        for( int i = 0 ; i < k ; i++ ){
            if( i > tos ){
                break;
            }
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
