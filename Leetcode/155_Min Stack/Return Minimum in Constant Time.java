class MinStack {

    /** initialize your data structure here. */
    
    int tos;
    int min ;
    int[] element = new int[1000000];
    int[] minimum = new int[1000000];
    
    public MinStack() {
        tos = -1;
        
    }
    
    public void push(int x) {
        if( tos == -1 ){
            minimum[++tos] = x;
            element[tos] = x;
            return;
        }
        element[tos+1] = x;
        if( x <= minimum[tos] ){
            minimum[++tos] = x;
        }
        else{
            minimum[tos+1]  = minimum[tos];
            tos++;
        }
    }
    
    public void pop() {
        tos--;
    }
    
    public int top() {
        return element[tos];
    }
    
    public int getMin() {
        return minimum[tos];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
