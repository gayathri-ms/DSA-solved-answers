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
stack<TreeNode*> s;
stack<TreeNode*> t;
class Samplenext{
    public:
        Samplenext(TreeNode* root)
        {
            checknext(root);
        } 
        void checknext(TreeNode* root)
        {
            if(!root)
                return;
            s.push(root);
            checknext(root->left);
        }
        int next()
        {
            TreeNode* temp=s.top();
            s.pop();
            checknext(temp->right);
            return temp->val;
        }
};
class Samplebefore{
    public:
    
        Samplebefore(TreeNode* root)
        {
            checkbefore(root);
        }
        void checkbefore(TreeNode* root)
        {
            if(!root)
                return;
            t.push(root);
            checkbefore(root->right);
        }
        int before()
        {
            TreeNode* temp=t.top();
            t.pop();
            checkbefore(temp->left);
            return temp->val;
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        Samplenext obj1(root);
        Samplebefore obj2(root);
        int i,j;
        i=obj1.next();
        j=obj2.before();
        while(i<j)
        {
            if((i+j)==k)
                return true;
            else if((i+j)<k)
                i=obj1.next();
            else if((i+j)>k)
                j=obj2.before();
        }
        return false;
    }
};