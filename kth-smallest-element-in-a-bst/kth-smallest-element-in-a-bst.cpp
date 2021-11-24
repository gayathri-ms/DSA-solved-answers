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
    int count=0;
    int check(TreeNode* root,int k)
    {
        if(!root)
            return -1;
        int l=check(root->left,k);
        if(l!=-1)
            return l;
        if(++count==k)
            return root->val;
        int r=check(root->right,k);
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        return check(root,k);
    }
};