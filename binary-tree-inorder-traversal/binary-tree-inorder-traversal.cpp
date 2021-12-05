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

// Morris Traversal - space complexity is O(1)

class Solution {
public:
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* temp=cur->left;
                while(temp->right && temp->right!=cur)
                { temp=temp->right; }
                if(!temp->right)
                {
                    temp->right=cur;
                    cur=cur->left;
                }
                else
                {
                    ans.push_back(cur->val);
                    temp->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};

// Normal Approach

class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root); 
        return ans;
    }
};
