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

//Faster Approach

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((!p && q) || (!q && p))
            return false;
        return ((p->val==q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right)));
    }
};

//first approach tried by me

class Solution {
public:
    bool ans=false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((!p && q) || (!q && p))
            return false;
        
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);
        if(p->val == q->val)
           ans=true;
        else
            ans=false;
        if(l && r && ans)
            return true;
        else
            return false;
    }
};
