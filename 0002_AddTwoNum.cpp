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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int plus = 0, tmp;
        ListNode *rt = nullptr, *trav = nullptr;
        while(l1 || l2 || plus){
            tmp = plus;
            if(l1) {tmp += l1->val; l1 = l1->next;}
            if(l2) {tmp += l2->val; l2 = l2->next;}
            plus = tmp/10;
            ListNode* nd = new ListNode(tmp%10);
            if(!rt){ 
                rt = nd;
                trav = rt;
            }
            else if(trav){
                trav->next = nd;
                trav = nd;
            }
        }

        return rt;
    }
};
