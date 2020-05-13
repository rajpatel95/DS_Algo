class MinStack {
public:
    /** initialize your data structure here. */
    
    typedef struct stackNode{
        int val;
        int min;
        
        
    };
    
    int tos;
    stackNode stacks[1000000];
    
    MinStack() {
        tos = -1;
    }
    
    void push(int x) {
        // If Stack is Empty
        if( tos == -1 ){
            stacks[++tos] = stackNode();
            stacks[tos].val = x;
            stacks[tos].min = x;
            return;
        }
        
        // For Non Empty Stack
        stacks[++tos] = stackNode();
        stacks[tos].val = x;
        if( x <= stacks[tos-1].min ){
            stacks[tos].min = x;
        }
        else{
            stacks[tos].min = stacks[tos-1].min;
        }
    }
    
    void pop() {
        tos--;
    }
    
    int top() {
        return stacks[tos].val;
    }
    
    int getMin() {
        return stacks[tos].min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
