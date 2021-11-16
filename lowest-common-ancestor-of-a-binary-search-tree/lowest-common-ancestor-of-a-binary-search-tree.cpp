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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root==p || root==q)
            return root;
        if((root->val > p->val && root->val < q->val) || (root->val<p->val && root->val > q->val))
            return root;
        TreeNode* temp1;
        TreeNode* temp2;
        if(root->val > p->val || root->val > q->val)
        {    
            temp1=lowestCommonAncestor(root->left,p,q);
            temp2=NULL;
        }
        else if(root->val<p->val || root->val<q->val)
        {    
            temp2=lowestCommonAncestor(root->right,p,q);
            temp1=NULL;
        }
        if(temp1 && !temp2)
            return temp1;
        if(!temp1 && temp2)
            return temp2;
        return NULL;
        
    }
};