// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle=0;
void dfs(int src,int par,vector<int>adj[],vector<bool>&vis)
{
    vis[src]=1;
    //cout<<src<<" "<<par<<endl;
    for(auto child:adj[src])
    {
        if(!vis[child]){
           dfs(child,src,adj,vis);
        }
        else
        {
            if(child!=par){
                cycle=1;
            }
        }       
    }
}
    bool isCycle(int n, vector<int> adj[]) {
    vector<bool>vis(n+1,0);
    cycle=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
           dfs(i,-1,adj,vis);
            if(cycle)
               {
                   return true;
               }
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