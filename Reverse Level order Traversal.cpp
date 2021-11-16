/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Can use either insert or use stack and push_back everything to vector

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    if(!root)
        return ans;
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    Node* temp;
    while(q.size())
    {
        temp=q.front();
        // s.push(temp->data);
        ans.insert(ans.begin(),temp->data);
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        
        q.pop();
    }
    // while(!s.empty())
    // {
    //     ans.push_back(s.top());
    //     s.pop();
    // }
    return ans;
}
