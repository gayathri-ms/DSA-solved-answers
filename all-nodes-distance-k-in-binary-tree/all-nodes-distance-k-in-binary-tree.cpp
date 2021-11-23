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
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode* , TreeNode*> m;
        m[root]=NULL;
        TreeNode* temp;
        while(q.size())
        {
            temp=q.front();
            if(temp->left)
            {
                q.push(temp->left);
                m[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                m[temp->right]=temp;
            }
            q.pop();
        }
        map<TreeNode*,bool> visited;
        visited[target]=true;
        q.push(target);
        int dis=0;
        while(q.size())
        {
            int s=q.size();
            if(dis++==k)
                break;
            for(int i=0;i<s;i++)
            {
                temp=q.front();
                if(m[temp] && !visited[m[temp]])
                {   
                    q.push(m[temp]);
                    visited[m[temp]]=true;
                }
                if(temp->left && !visited[temp->left])
                {    
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right])
                {    
                    visited[temp->right]=true;
                    q.push(temp->right);
                }
                q.pop();
            }
        }
        vector<int> ans;
        while(q.size())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};