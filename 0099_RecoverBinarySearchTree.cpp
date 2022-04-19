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
    void recoverTree(TreeNode* root) {
        order(root);
        
        int tmp = fst->val;
        fst->val = snd->val;
        snd->val = tmp;
    }
    
private:
    void order(TreeNode* nd){
        if(!nd) return;
        order(nd->left);
        
        if(!fst && prev->val > nd->val)
            fst = prev;
        if(fst && prev->val >= nd->val)
            snd = nd;
        prev = nd;
        
        order(nd->right);
    }
    
    TreeNode *fst, *snd;
    TreeNode *prev = new TreeNode(INT_MIN);
};
