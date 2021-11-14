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
    vector<int> v;
    vector<vector<int>> ans;
    void check(TreeNode* root, int targetSum)
    {
        if(!root)
            return;
        v.push_back(root->val);
        if(!root->left && !root->right && targetSum-root->val == 0)
            ans.push_back(v);
        check(root->left,targetSum-root->val);
        check(root->right,targetSum-root->val);
        targetSum-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        check(root,targetSum);
        return ans;
    }
};