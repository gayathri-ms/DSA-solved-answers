class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* suc=NULL;
    void check(Node* root,Node* x)
    {
        if(!root)
            return;
        if(root->data <= x->data)
            check(root->right,x);
        else if(root->data > x->data)
        {
            suc=root;
            check(root->left,x);
        }
        return;
        
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        check(root,x);
        return suc;
    }
};
