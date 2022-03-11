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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* proc = head, *nd = head;
        int count = 0;
        while(proc->next){
            count++;
            proc = proc->next;
        }
        count++;
        k = k%count;
        if(k == 0) return head;
        
        for(int i=1; i<count-k; i++){
            nd = nd->next;
        }
        ListNode* rt = nd->next;
        nd->next = nullptr;
        proc->next = head;
        
        return rt;
    }
};
