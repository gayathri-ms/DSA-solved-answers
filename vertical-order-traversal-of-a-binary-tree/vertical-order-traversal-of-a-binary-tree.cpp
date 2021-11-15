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
    map<int,map<int,multiset<int>>> mp;
    void vertical(TreeNode* root,int col,int row)
    {
        if(!root)
            return;
        mp[col][row].insert(root->val);
        vertical(root->left,col-1,row+1);
        vertical(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vertical(root,0,0);
        for(auto it:mp)
        {
            vector<int> v;
            for(auto x:it.second)
            {
                v.insert(v.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};