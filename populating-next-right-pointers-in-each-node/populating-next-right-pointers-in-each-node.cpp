/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> v;
        if(!root)
            return root;
        v.push(root);
        v.push(NULL);
        while(true)
        {
            if(v.front()==NULL && v.size()==1)
                break;
            Node* temp=v.front();
            v.pop();
            if(v.front()==NULL)
            {   v.pop();
                temp->next=NULL;
                if(temp->left != NULL)
                    v.push(temp->left);
                if(temp->right != NULL)
                    v.push(temp->right);
                v.push(NULL);
            }
            else
            {
                temp->next=v.front();
                if(temp->left != NULL)
                    v.push(temp->left);
                if(temp->right != NULL)
                    v.push(temp->right);
            }
        }
        
        return root;
    }
};