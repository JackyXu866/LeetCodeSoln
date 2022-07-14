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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0, in = 0;
        return recur(preorder, inorder, -3001, pre, in);
    }
    
private:
    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int search, int& pre, int& in){
        if(pre >= preorder.size()) return nullptr;
        if(inorder[in] == search) {in++; return nullptr;}
        
        TreeNode* n = new TreeNode(preorder[pre++]);
        n -> left = recur(preorder, inorder, n->val, pre, in);
        n -> right = recur(preorder, inorder, search, pre, in);
        
        return n;
    }
};
