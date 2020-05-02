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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* ans = NULL;
        ListNode* head = NULL;
            
        stack<int> st1, st2;
        ans = new ListNode(0);
        head = ans;
            
        while( l1 != NULL ){
            st1.push( l1->val );
            l1 = l1->next;
        }
        
        while( l2 != NULL ){
            st2.push( l2->val );
            l2 = l2->next;
        }
           
        int carry = 0;

        while( !st1.empty() || !st2.empty() ){
            int x = 0 ,y = 0;
            
            if( !st1.empty() ){
                x = st1.top();
                st1.pop();
            }
            
            if( !st2.empty() ){
                y = st2.top();
                st2.pop();
            }
            
            int sum = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            
            ListNode* new_node = new ListNode(sum);
            new_node->next = head->next;
            head->next = new_node;
            
        }
        
        if( carry != 0 ){
            ListNode* new_node = new ListNode(carry);
            new_node->next = head->next;
            head->next = new_node;
        }
        
        return head->next;
            
           
    }
};
