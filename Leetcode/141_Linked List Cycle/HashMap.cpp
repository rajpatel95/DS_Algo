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
        map<ListNode*, int> mp;
        
        while( head != NULL ){
            if( mp.find(head) != mp.end() ){
                return true;
            }
            mp.insert({ head, 0 });
            head = head->next;
        }
        
        return false;
        
    }
};
