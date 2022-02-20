// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int x,vector<int> adj[],vector<int> &visited)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(x,-1));
        visited[x]=1;
        
        while(!q.empty())
        {
            int prev=q.front().second;
            int node=q.front().first;
            q.pop();
            for(auto a: adj[node])
            {
                if(visited[a] && prev != a)
                    return true;
                else
                {
                    if(!visited[a])
                    {
                        visited[a]=1;
                        q.push(make_pair(a,node));
                    }
                    
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V,0);
        queue<pair<int,int>> q;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited))
                    return true;
            }
                
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends