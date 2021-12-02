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
    TreeNode* check(vector<int> &preorder,int max,int &n)
    {
        if(n==preorder.size())
            return NULL;
        TreeNode* temp;
        if(max < preorder[n])
            return NULL;
        else
            temp=new TreeNode(preorder[n++]);
        
        temp->left=check(preorder,temp->val,n);
        temp->right=check(preorder,max,n);
        
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=0;
        return check(preorder,INT_MAX,n);
    }
};