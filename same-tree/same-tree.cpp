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
    bool ans=false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((!p && q) || (!q && p))
            return false;
        
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);
        if(p->val == q->val)
           ans=true;
        else
            ans=false;
        if(l && r && ans)
            return true;
        else
            return false;
    }
};