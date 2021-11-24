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
    TreeNode* tree(vector<int> inorder,int instart,int inend,vector<int> postorder,int poststart,int postend)
    {
        if(instart>inend || poststart>postend)
            return NULL;
        TreeNode* root=new TreeNode(postorder[poststart]);
        int index=mp[root->val];
        int no_left=index-instart;
        root->right=tree(inorder,instart,index-1,postorder,poststart+1,poststart+no_left);
        root->left=tree(inorder,index+1,inend,postorder,poststart+no_left+1,postend);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        reverse(postorder.begin(),postorder.end());
        reverse(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* ans= tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        return ans;
    }
};