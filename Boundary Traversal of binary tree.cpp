
class Solution {
public:
    vector<int> v;
    void leftboundary(Node* root)
    {
        if(!root)
            return;
        if(root->left)
        {    
            v.push_back(root->data);
            leftboundary(root->left);
        }
        else if(root->right)
        {    
            v.push_back(root->data);
            leftboundary(root->right);
        }
    }
    void leafnodes(Node* root)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
            v.push_back(root->data);
        leafnodes(root->left);
        leafnodes(root->right);
    }
    void reverserightboundary(Node* root)
    {
        if(!root)
            return;
        
        if(root->right)
        {
            reverserightboundary(root->right);
            v.push_back(root->data);
        }
        else if(root->left)
        {    
            reverserightboundary(root->left);
            v.push_back(root->data);
        }
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(!root)
            return v;
        v.push_back(root->data);
        leftboundary(root->left);
        leafnodes(root);
        reverserightboundary(root->right);
        
        return v;
    }
};
