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
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* rt = new TreeNode();
        curr = rt;
        
        order(root);
        
        return rt->right;
    }
    
private:
    TreeNode* curr;
    void order(TreeNode* root) {
        if(!root) return;
        order(root->left);
        root->left = nullptr;
        curr->right = root;
        curr = root;
        order(root->right);
    }
};
