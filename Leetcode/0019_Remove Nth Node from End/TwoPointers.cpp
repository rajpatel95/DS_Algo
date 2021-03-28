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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Maintaining 2 Pointers with a difference of 'n' and traverse the faster pointer to the End
        
        struct ListNode* dummy = head;

        struct ListNode* fast = head;

        for( int i = 0 ; i <= n ; i++ ){
            if( fast == NULL ){
                return dummy->next;
            }
            fast = fast->next;
        }
        
        while( fast != NULL ){
            head = head->next;
            fast = fast->next;
        }
        
        head->next = head->next->next;

        return dummy;



    }
};
