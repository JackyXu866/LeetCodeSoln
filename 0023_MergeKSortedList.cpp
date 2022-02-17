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

bool compNode(const ListNode* a, const ListNode* b){
    return a->val < b->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> all;
        for(ListNode* i : lists){
            ListNode* tmp = i;
            while(tmp){
                all.push_back(tmp);
                tmp = tmp->next;
            }
        }
        if(all.empty()) return NULL;
        sort(all.begin(), all.end(), compNode);
        
        for(int i=0; i<all.size()-1; i++){
            all[i]->next = all[i+1];
        }
        all[all.size()-1]->next = NULL;
        
        return all[0];
    }
};
