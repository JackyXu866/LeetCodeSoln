/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> nd;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(nd.find(node->val) != nd.end()) return nd[node->val];
        Node* newN = new Node(node->val);
        nd[node->val] = newN;
        for(Node* i : node->neighbors){
            newN->neighbors.push_back(cloneGraph(i));
        }
        
        return newN;
    }
};
