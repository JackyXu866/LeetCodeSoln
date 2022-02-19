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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> rt;
        dfs(root1, rt);
        dfs(root2, rt);
        sort(rt.begin(), rt.end());
        return rt;
    }
    
    void dfs(TreeNode* r, vector<int>& rt){
        if(!r) return;
        dfs(r->left, rt);
        dfs(r->right, rt);
        rt.push_back(r->val);
    }
};
