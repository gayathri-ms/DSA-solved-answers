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
    TreeNode* x=NULL;
    TreeNode* prev=NULL;
    TreeNode* mid=NULL;
    TreeNode* next=NULL;
    void check(TreeNode* root)
    {
        if(!root)
            return;
        check(root->left);
        if(x && x->val>root->val)
        {
            if(!prev && !mid)
            {
                prev=x;
                mid=root;
            }
            else
                next=root;
        }
        x=root;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        check(root);
        if(prev && next)
            swap(prev->val,next->val);
        else if(prev && mid)
            swap(prev->val,mid->val);
    }
};