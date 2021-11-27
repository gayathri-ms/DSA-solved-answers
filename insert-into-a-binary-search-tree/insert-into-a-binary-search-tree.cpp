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
    void check(TreeNode* root,int val)
    {
        if(!root)
            return;
        if(root->left && root->val > val)
            check(root->left,val);
        else if(!root->left && root->val > val)
        {
            root->left=new TreeNode(val);
            return;
        }
        else if(root->right && root->val < val)
            check(root->right,val);
        else if(!root->right && root->val < val)
        {
            root->right=new TreeNode(val);
            return;
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {    
            TreeNode* temp=new TreeNode(val);
            root=temp;
        }
        else
            check(root,val);
        return root;
    }
};