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
        int lh=check(root->left);
        int rh=check(root->right);
        maximum=max(maximum,(lh+rh));
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=check(root);
        return maximum;
    }
};