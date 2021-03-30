/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    typedef struct Node{
        int value;
        Node *next;
        
        Node(int x){
            value = x;
            next = NULL;
        }
    };
    Node *head, *current;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        head = new Node(-1); // All Numbers are >0 in this example.
        current = head;
        
	    for(int x: nums){
            head->next = new Node(x);
            head = head->next;
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        cout<<"Peek(): "<<current->next->value<<endl;
        return current->next->value;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        
        int ans = current->next->value;
	    current = current->next;
        
        return ans;
	}
	
	bool hasNext() const {
	    return !(current->next == NULL);
	}
};
