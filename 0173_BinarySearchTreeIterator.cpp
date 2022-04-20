/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        order(root);
    }
    
    int next() {
        int rt = q.front()->val;
        q.pop();
        return rt;
    }
    
    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<TreeNode*> q;
    
    void order(TreeNode* root){
        if(!root) return;
        order(root->left);
        q.push(root);
        order(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
