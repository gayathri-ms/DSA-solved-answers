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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        TreeNode* temp;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(root->val);
        ans.push_back(v);
        v.clear();
        q.push(NULL);
        while(true)
        {
            if(q.size()==1 && q.front()==NULL)
                break;
            if(!q.empty() && q.front()==NULL)
            {    
                q.push(NULL);
                ans.push_back(v);
                v.clear();
                q.pop();
            }
            temp=q.front();
            if(temp->left)
            {
                q.push(temp->left);
                v.push_back(temp->left->val);
            }
            if(temp->right)
            {
                q.push(temp->right);
                v.push_back(temp->right->val);
            }
            q.pop();
            
        }
        return ans;
    }
};