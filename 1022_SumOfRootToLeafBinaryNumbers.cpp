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
    int sumRootToLeaf(TreeNode* root) {
        int rt = 0;
        dfs(root, 0, rt);
        return rt;
    }
    
    void dfs(TreeNode* nd, int i, int& s){
        if(!nd)  return;
        i = i*2 + nd->val;
        if(nd->left) dfs(nd->left, i, s);
        if(nd->right) dfs(nd->right, i, s);
        else if(!nd->left && !nd->right) s += i;

    }
    
};
