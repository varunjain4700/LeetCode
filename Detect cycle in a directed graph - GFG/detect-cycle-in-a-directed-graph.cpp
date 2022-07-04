// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,int par,vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis)
    {
        vis[src]=1;
        dfsvis[src]=1;
        for(auto child:adj[src])
        {
            if(!vis[child])
            {
                if(dfs(child,src,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[child])
            {
                return true;
            }
        }
        dfsvis[src]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector<bool>vis(n,0),dfsvis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis,dfsvis))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends