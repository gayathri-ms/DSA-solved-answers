// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode* root,int b,vector<int> &v)
{
    if(!root)
        return false;
    v.push_back(root->val);
    if(root->val == b)
        return true;
    if(check(root->left,b,v) || check(root->right,b,v))
        return true;
    v.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool x=check(A,B,ans);
    return ans;
}
