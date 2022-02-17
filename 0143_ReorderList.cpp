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
    void reorderList(ListNode* head) {
        ListNode *mid = head, *end = head, *prev=NULL, *tmp=NULL;
        // get mid
        while(end && end->next){
            mid = mid->next;
            end = end->next->next;
        }

        // reverse second half
        while(mid){
            tmp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = tmp;
        }
        mid = prev;

        while(mid && head){
            tmp = head->next;
            head->next = prev;
            prev = mid->next;
            head = tmp;
            mid->next = head;
            mid = prev;
        }
        if (head && head->next) head->next->next = NULL;
    }
};
