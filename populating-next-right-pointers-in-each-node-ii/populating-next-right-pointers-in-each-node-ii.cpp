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
        if(!root)
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* temp=root;
        while(true)
        {
            if(q.size()==1 && q.front()==NULL)
                break;
            if(q.size()>1 && q.front()==NULL)
            {
                q.pop();
                q.push(NULL);
            }
            temp=q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
            temp->next=q.front();
        }
        return root;
    }
};