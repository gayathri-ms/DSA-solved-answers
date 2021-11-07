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
    int leftsum(TreeNode* root , int cur )
    {
        if(root)
        {
            if(!root->left && !root->right && cur==1)
                return root->val;
            return leftsum(root->left , 1) + leftsum(root->right , 0) ;
        }
        return 0;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return leftsum(root , 0);
    }
};