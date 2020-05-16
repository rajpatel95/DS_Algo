/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* cycleStart(ListNode* slow, ListNode* fast, ListNode* head){
        slow = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while( (fast != NULL) && (slow != NULL) ){
            if( slow->next == NULL || fast->next == NULL || fast->next->next == NULL ){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast ){
                return cycleStart(slow, fast, head);
            }
        }
        
        return NULL;
    }
};
