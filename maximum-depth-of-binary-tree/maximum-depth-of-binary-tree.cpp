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
    int depth=0;
    void ans(TreeNode* root,int level)
    {
        if(!root)
            return;
        depth=max(depth,level);
        ans(root->left,level+1);
        ans(root->right,level+1);
            
    }
    int maxDepth(TreeNode* root) {
        ans(root,1);
        return depth;
    }
};