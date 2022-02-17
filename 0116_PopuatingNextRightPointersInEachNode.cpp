/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* trav = root, *beg = root;
        while(trav->left){
            if(beg == trav) beg = trav->left;
            trav->left->next = trav->right;
            if(trav->next){
                trav->right->next = trav->next->left;
            }
            if(trav->next) trav = trav->next;
            else trav = beg;
        }
        return root;
    }
};
