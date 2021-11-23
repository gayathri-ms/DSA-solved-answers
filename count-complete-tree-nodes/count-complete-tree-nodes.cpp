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
    int leftheight(TreeNode* root)
    {
        if(!root)
            return 0;
        int height=0;
        while(root)
        {
            root=root->left;
            height++;
        }
        return height;
    }
    int rightheight(TreeNode* root)
    {
        if(!root)
            return 0;
        int height=0;
        while(root)
        {
            root=root->right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh)
            return (1<<lh)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right) ;
    }
};