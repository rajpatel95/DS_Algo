class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int q[10005]; // This is bad approach, next time solve with Linked List
    int max_size, front, rear, curr_size; 
	
    MyCircularQueue(int k) {
        max_size = k;
        front = 0;
        rear = 0;
        curr_size = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if( curr_size == max_size){
            return false;
        }
        
        q[rear++] = value;
        curr_size++;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(curr_size == 0 ){
            return false;
        }
        
        front++;
        curr_size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(curr_size == 0 ){
            return -1;
        }
        return q[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(curr_size == 0 ){
            return -1;
        }
        return q[rear - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if( curr_size == 0 ){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(curr_size == max_size){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
