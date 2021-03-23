/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int> heap; // Min-heap, so insert negative of every value
        
        for(int i = 0 ; i < lists.size(); i++){
            ListNode *head;
            head = lists[i];
            
            while(head != NULL){
           
                heap.push(-head->val);
                head = head->next;
            }
        }
        
        ListNode *node = new ListNode(0);
        ListNode *ans = node;
    
        while( !heap.empty() ){
          
            node->next = new ListNode(-heap.top());
            heap.pop();
            node = node->next;
        }
        
        return ans->next;
    }
};
