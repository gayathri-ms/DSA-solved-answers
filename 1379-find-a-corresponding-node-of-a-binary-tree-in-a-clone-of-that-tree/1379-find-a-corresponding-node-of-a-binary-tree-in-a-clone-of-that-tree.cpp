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
    
    void check(TreeNode* ori, TreeNode* copy, TreeNode* t , TreeNode* &a)
    {
        if(ori == NULL)
            return;
        if(t == ori)
        {    
            a= copy;
            return;
        }
        check(ori->left , copy->left, t , a);
        check(ori->right , copy->right, t, a);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        check(original , cloned, target , ans);
        return ans;
    }
};