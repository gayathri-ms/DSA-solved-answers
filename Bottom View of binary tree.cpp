class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root)
            return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        int hd=0;
        q.push(make_pair(root,0));
        Node* temp;
        
        while(q.size())
        {
            temp=q.front().first;
            hd=q.front().second;
            mp[hd]=temp->data;
            if(temp->left)
                q.push(make_pair(temp->left,hd-1));
            if(temp->right)
                q.push(make_pair(temp->right,hd+1));
            q.pop();
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
