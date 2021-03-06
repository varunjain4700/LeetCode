// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle=0;
bool dfs(int src,int par,vector<int>adj[],vector<bool>&vis)
{
    vis[src]=1;
    //cout<<src<<" "<<par<<endl;
    for(auto child:adj[src])
    {
        if(!vis[child]){
           if(dfs(child,src,adj,vis))
            return true;
        }
        else
        {
            if(child!=par){
               return true;
            }
        }       
    }
    return false;
}
bool bfs(int src,int par,vector<int>adj[],vector<bool>&vis)
{
    queue<pair<int,int>>q;
    q.push({src,par});
    vis[src]=1;
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        int v=p.first,parent=p.second;
        for(auto child:adj[v])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push({child,v});
            }
            else
            {
                if(child!=parent)
                    return true;
            }
        }
    }
    return false;
}
    bool isCycle(int n, vector<int> adj[]) {
    vector<bool>vis(n+1,0);
    cycle=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
           if(bfs(i,-1,adj,vis))
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