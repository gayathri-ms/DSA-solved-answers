/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<pair<Node*,int>> q;
        stack<int> left;
        vector<int> right;
        q.push(make_pair(root,0));
        int hd=0,l=0,r=0;
        Node* temp;
        while(q.size()){
            temp=q.front().first;
            hd=q.front().second;
            if(hd<l)
            {
                left.push(temp->data);
                l=hd;
            }
            if(hd>r)
            {
                right.push_back(temp->data);
                r=hd;
            }
            if(temp->left)
                q.push(make_pair(temp->left,hd-1));
            if(temp->right)
                q.push(make_pair(temp->right,hd+1));
            q.pop();
        }
        while(left.size())
        {
            cout<<left.top()<<" ";
            left.pop();
        }
        cout<<root->data<<" ";
        for(int i=0;i<right.size();i++)
        {
            cout<<right[i]<<" ";
        }
    
    }

};
