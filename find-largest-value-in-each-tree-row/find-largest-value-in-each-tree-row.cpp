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
    vector<int> ans;
    void check(TreeNode* root,int level)
    {
        if(!root)
            return;
        if(ans.size()>level && ans[level]<root->val)
            ans[level]=root->val;
        else if(ans.size()<=level)
            ans.push_back(root->val);
        check(root->left,level+1);
        check(root->right,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return ans;
        check(root,0);
        return ans;
    }
};