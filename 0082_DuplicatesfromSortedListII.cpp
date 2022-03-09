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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* prec = dummy;

        while(head){
            if(head->next && head->next->val == head->val){
                int val = head->val;
                while(head && head->val == val)
                    head = head->next;
                prec->next = head;
            }
            else{
                prec = prec->next;
                head = head->next;
            }
        }

        return dummy->next;
    }
};
