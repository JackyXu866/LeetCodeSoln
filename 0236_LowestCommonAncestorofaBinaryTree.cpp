/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return rt;
    }
    
private:
    TreeNode* rt = nullptr;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return 0;
        
        int curr = (p == root) || (q == root);
        int r = dfs(root->right, p, q);
        int l = dfs(root->left, p, q);
        
        if(curr+r+l >= 2 && !rt) rt = root;
        
        return r+l+curr;
    }
};
