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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* merged = new ListNode(0);
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* headf = merged;
        
        while( head1 != NULL || head2 != NULL ){
            if(head1 == NULL){
                 merged->next = new ListNode(head2->val);
                 merged = merged->next;
                 head2 = head2->next;
            }
            else if( head2 == NULL){
                 merged->next = new ListNode(head1->val);
                 merged = merged->next;
                 head1 = head1->next;
            }
            else if( head1->val <= head2-> val){
                merged->next = new ListNode(head1->val);
                merged = merged->next;
                head1 = head1->next;
            }
            else if(head1->val > head2-> val){
                merged->next = new ListNode(head2->val);
                merged = merged->next;
                head2 = head2->next;
            }
        }
        return headf->next;
    }
};
