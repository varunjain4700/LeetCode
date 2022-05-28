// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool ans=false;
bool solve(int idx,int m,int n,vector<vector<int>>&adj,vector<int>&color)
{
    if(idx==n)
    {
        return true;
    }
    for(int i=0;i<m;i++)
    {
        bool flag=0;
        for(auto child:adj[idx])
        {
            if(color[child]==i&&child!=idx){
                flag=1;
                break;
            }
        }
        if(flag)
            continue;
        color[idx]=i;
        if(solve(idx+1,m,n,adj,color))
            return true;
       color[idx]=-1;
        
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<vector<int>>adj;
    vector<int>color(n+1,-1);
    adj.resize(n+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1)
                adj[i].push_back(j);
        }
    }
    ans=false;
    return solve(0,m,n,adj,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends