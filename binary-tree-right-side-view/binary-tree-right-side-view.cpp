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
    int cur=-1;
    void findans(TreeNode* root , int level)
    {
        if(!root)
            return;
        if(level>cur)
        {
            ans.push_back(root->val);
            cur++;
        }  
        findans(root->right , level+1);
        findans(root->left , level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        findans(root , 0);
        return ans;
    }
};