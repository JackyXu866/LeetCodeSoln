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
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0) return ++rt;
        return rt;
    }
    
private:
    int rt = 0;
    int dfs(TreeNode* n){
        if(!n) return 2;
        int l = dfs(n->left);
        int r = dfs(n->right);
        
        if(l == 0 || r == 0){
            rt++;
            return 1;
        }
        
        if(l == 1 || r == 1) return 2;
        return 0;
    }
};
