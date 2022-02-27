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
    unsigned long int widthOfBinaryTree(TreeNode* root) {
       vector<unsigned long int> left;
        return dfs(root, left, 0, 1);
    }
    
private:
    unsigned long int dfs(TreeNode* nd, vector<unsigned long int>& left, unsigned long int depth, unsigned long int no){
        if(!nd) return 0;
        if(depth >= left.size()) left.push_back(no);
        return max({no-left[depth]+1, dfs(nd->left, left, depth+1, 2*no), dfs(nd->right, left, depth+1, 2*no+1)});
    }
};
