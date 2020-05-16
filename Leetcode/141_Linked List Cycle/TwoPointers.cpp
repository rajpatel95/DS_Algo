/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while( (fast != NULL) && (slow != NULL) ){
            if( slow->next == NULL || fast->next == NULL || fast->next->next == NULL ){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
             if( slow == fast ){
                return true;
            }
        }
        
        return false;
        
    }
};
