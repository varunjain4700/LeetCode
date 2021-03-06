class Solution
{
    public:
       	//Seems like a DSU problem.Lets try.
        vector<int> par, sz;
    void initialise(int n)
    {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void make_union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (sz[y] > sz[x])
            swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    int makeConnected(int n, vector<vector < int>> &edges)
    {
        if (edges.size() < n - 1)
            return -1;
        initialise(n);
        for (int i = 0; i < edges.size(); i++)
        {
            if (find(edges[i][0]) != find(edges[i][1]))
            {
                make_union(edges[i][0], edges[i][1]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)	//finding no. of connected components
        {
            if (par[i] == i)
                cnt++;
        }
        return cnt - 1;
    }
};