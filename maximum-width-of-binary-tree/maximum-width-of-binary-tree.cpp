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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        q.push({NULL,-1});
        TreeNode* temp;
        int v,f=0,maxi=INT_MIN;
        while(q.size())
        {
            temp=q.front().first;
            v=q.front().second;
            if(temp==NULL)
            {
                q.pop();
                f=q.front().second;
                q.push({NULL,-1});
                temp=q.front().first;
                v=q.front().second;
            }
            if(temp)
            {
                if(temp->left)
                    q.push(make_pair(temp->left,2*v-f));
                if(temp->right)
                    q.push(make_pair(temp->right,2*v-f+1));
            }
            q.pop();
            if(q.front().first == NULL)
            {
                maxi=max(maxi,v-f+1);
            }
        }
        
        return maxi;
        
    }
};