// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	vector<int>par,sz;
	int find(int x)
	{
	    if(x==par[x])
	        return x;
	   return par[x]=find(par[x]);
	}
	int union_set(int x,int y)
	{
	    x=find(x);
	    y=find(y);
	    if(sz[y]>sz[x])
	        swap(x,y);
	   sz[x]+=sz[y];
	   par[y]=x;
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<vector<int>>v;
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                v.push_back({adj[i][j][1],i,adj[i][j][0]});
            }
        }
        sort(v.begin(),v.end());
        int edges=0,cost=0;
        int i=0;
        while(edges!=n-1)
        {
            //cout<<v[i][0]<<endl;
            if(find(v[i][1])!=find(v[i][2]))
            {
                edges++;
                cost+=v[i][0];
                union_set(v[i][1],v[i][2]);
            }
            i++;
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends