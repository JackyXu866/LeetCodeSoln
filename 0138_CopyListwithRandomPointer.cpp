/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        // save new node in the random, and old random node to new node's next
        Node* tmp = head;
        while(tmp){
            Node* r = tmp->random;
            tmp->random = new Node(tmp->val);
            tmp->random->next = r;
            tmp = tmp->next;
        }
        
        // update new node(tmp->random)'s random to new random node
        tmp = head;
        while(tmp){
            Node* r = tmp->random->next;
            if(r) tmp->random->random = r->random;
            tmp = tmp->next;
        }
        
        // get back origin list's random and link new list
        tmp = head;
        Node* rt = new Node(-1), *res = rt;
        while(tmp){
            Node* r = tmp->random->next;
            rt->next = tmp->random;
            // cout << rt->next->val <<": ";
            // if(rt->next->random) cout << rt->next->random->val << endl;
            tmp->random = r;
            rt = rt->next;
            tmp = tmp->next;
        }
        rt->next = nullptr;
        
        return res->next;
    }
};
