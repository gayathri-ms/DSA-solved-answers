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
    int maximum=INT_MIN;
    int check(TreeNode* root)
    {
        if(!root)
            return 0;
        int lh=max(0,check(root->left));
        int rh=max(0,check(root->right));
        maximum=max(maximum,(lh+rh+root->val));
        return (max(lh,rh)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int value=check(root);
        return maximum;
    }
};