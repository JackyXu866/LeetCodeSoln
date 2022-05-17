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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> oq;
        queue<TreeNode*> cq;
        oq.push(original);
        cq.push(cloned);
        
        while(!oq.empty() && !cq.empty()){
            int n = oq.size();
            for(; n>0; n--){
                TreeNode* tmpO = oq.front();
                oq.pop();
                TreeNode* tmpC = cq.front();
                cq.pop();
                
                if(tmpO == target) return tmpC;
                if(tmpO->left){
                    oq.push(tmpO->left);
                    cq.push(tmpC->left);
                }
                if(tmpO->right){
                    oq.push(tmpO->right);
                    cq.push(tmpC->right);
                }
            }
        }
        
        return nullptr;
    }
};
