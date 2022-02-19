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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        ListNode* fwd = head;
        ListNode* ffwd = head;
        if(ffwd){
            fwd = fwd->next;
            if(!ffwd->next) return nullptr;
            ffwd = ffwd->next->next;
        }
        while(ffwd && ffwd->next){
            fwd = fwd->next;
            ffwd = ffwd->next->next;
            prev = prev->next;
        }
        prev->next = fwd->next;
        return head;
    }
};
