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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        int flag=0;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            if(q.front()!=NULL)
            {
                root=q.front();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                q.pop();
                if(flag==0)
                    v.push_back(root->val);
                else
                    v.insert(v.begin(),root->val);
            }
            else
            {
                q.pop();
                ans.push_back(v);
                v.clear();
                flag=!flag;
                if(!q.empty())
                    q.push(NULL);
            }   
        }
        return ans;
    }
};