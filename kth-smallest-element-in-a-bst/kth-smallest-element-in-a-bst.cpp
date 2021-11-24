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
    priority_queue<int> pq;
    void check(TreeNode* root,int k)
    {
        if(!root)
            return;
        if(pq.size()!=k)
            pq.push(root->val);
        else
        {
            if(pq.top()>root->val)
            {
                pq.pop();
                pq.push(root->val);
            }
        }
        check(root->left,k);
        check(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        check(root,k);
        return pq.top();
    }
};