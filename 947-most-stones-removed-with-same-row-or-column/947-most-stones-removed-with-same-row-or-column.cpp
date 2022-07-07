class Solution
{
    public:
        vector<int> par, sz;
    void initialise(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == par[x])
            return x;
        return find(par[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (y > x)
            swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    int removeStones(vector<vector < int>> &stones)
    {
        int n = stones.size();
        par.resize(n + 1);
        sz.resize(n + 1);
        initialise(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    if (find(i) != find(j))	//haven't been grouped together
                        merge(i, j);
            }
        }
        int cnt = 0;	//number of stones that can't be removed,i.e number of components
        for (int i = 0; i < n; i++)
        {
            if (par[i] == i)
                cnt++;
        }
        return n - cnt;
    }
};