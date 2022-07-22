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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0), *lag = new ListNode(0);
        ListNode* lh = less, *gh = lag;
        
        while(head){
            if(head->val < x){
                less->next = head;
                head = head->next;
                less = less->next;
                less->next = nullptr;
            }
            else{
                lag->next = head;
                head = head->next;
                lag = lag->next;
                lag->next = nullptr;
            }
        }
        
        less->next = gh->next;
        return lh->next;
    }
};
