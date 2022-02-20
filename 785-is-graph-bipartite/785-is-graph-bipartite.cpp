class Solution {
public:
    bool bfs(int x,vector<int> &visited,vector<vector<int>>& graph)
    {
        queue<int> q;
        q.push(x);
        visited[x]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto a:graph[node])
            {
                if(visited[a] == -1)
                {
                    visited[a]=!visited[node];
                    q.push(a);
                }
                else
                {
                    if(visited[a] == visited[node])
                        return false;
                }
            }
        }
        
        return true;
    }
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == -1)
                if(!bfs(i,visited,graph))
                    return false;
        }
        return true;
    }
};