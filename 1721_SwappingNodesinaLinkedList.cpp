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
        ListNode* fst = head, *snd = head, *nd = head;
        
        while(nd){
            k--;
            if(k == 0) fst = nd;
            else if(k < 0) snd = snd->next;
            nd = nd->next;
        }
        
        swap(fst->val, snd->val);
        return head;
    }
};
