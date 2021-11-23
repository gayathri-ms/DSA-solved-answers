int Solution::solve(TreeNode* A, int B) {
    queue<TreeNode*> q;
    q.push(A);
    unordered_map<TreeNode*,TreeNode*> m;
    m[A]=NULL;
    TreeNode* temp;
    TreeNode* target;
    while(q.size())
    {
        temp=q.front();
        if(temp->val == B)
            target=temp;
        if(temp->left)
        {
            q.push(temp->left);
            m[temp->left]=temp;
        }
        if(temp->right)
        {
            q.push(temp->right);
            m[temp->right]=temp;
        }
        q.pop();
    }
    unordered_map<TreeNode*,bool> visited;
    visited[target]=true;
    q.push(target);
    int dis=0;
    while(q.size())
    {
        int s=q.size();
        dis++;
        for(int i=0;i<s;i++)
        {
            temp=q.front();
            if(m[temp] && !visited[m[temp]])
            {
                visited[m[temp]]=true;
                q.push(m[temp]);
            }
            if(temp->left && !visited[temp->left])
            {
                visited[temp->left]=true;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right])
            {
                visited[temp->right]=true;
                q.push(temp->right);
            }
            q.pop();
        }
    }
    return dis;
}
