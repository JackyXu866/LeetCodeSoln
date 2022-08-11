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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size());
    }
    
private:
    TreeNode* recur(vector<int>& n, int b, int e){
        if(b >= e) return nullptr;
        int m = b+(e-b)/2;
        TreeNode* rt = new TreeNode(n[m]);
        rt->left = recur(n, b, m);
        rt->right = recur(n, m+1, e);
        return rt;
    }
};
