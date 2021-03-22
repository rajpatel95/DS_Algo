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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> temp;
        ListNode* ans = new ListNode();
        ListNode* ret_ans = ans;
        
        while( head != NULL ){
            temp.push_back(head->val);
            head = head->next;
        }
    
        swap(temp[k-1],temp[temp.size()-k]);
        
        int i = 0;
        while(i < temp.size()){
            ListNode* newNode = new ListNode(temp[i++]);
            ans->next = newNode;
            ans = ans->next;
        }
        
        return ret_ans->next;
        
    }
};
