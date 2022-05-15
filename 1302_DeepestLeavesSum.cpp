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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            sum = 0;
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if(tmp->right) q.push(tmp->right);
                if(tmp->left) q.push(tmp->left);
            }
        }
        return sum;
    }
};
