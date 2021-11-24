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
    map<int,int> mp;
    TreeNode* Tree(vector<int> preorder,int prestart,int preend, vector<int> inorder,int instart,int inend)
    {
        if(prestart>preend || instart>inend)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int index=mp[root->val];
        int no_left=index-instart;
        root->left=Tree(preorder,prestart+1,prestart+no_left,inorder,instart,index-1);
        root->right=Tree(preorder,prestart+no_left+1,preend,inorder,index+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* ans;
        ans=Tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return ans;
    }
};