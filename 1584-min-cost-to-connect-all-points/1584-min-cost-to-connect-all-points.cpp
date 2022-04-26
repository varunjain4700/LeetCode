class Solution
{
    public:
        vector<int> par, size;
    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (size[y] > size[x])
            swap(x, y);
        size[x] += size[y];
        par[y] = x;
    }
    static bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
    {
        return a.second < b.second;
    }
    int minCostConnectPoints(vector<vector < int>> &points)
    {
        int n = points.size();
        par.resize(n + 1, 0);
        size.resize(n + 1, 0);
        init(n);
        vector<pair<pair<int, int>, int>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dis = abs(points[j][0] - points[i][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({
		{
                        i,
                        j
                    },
                    dis });
            }
        }
        sort(adj.begin(), adj.end(), cmp);
        int cnt = 0, ans = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            int a = adj[i].first.first, b = adj[i].first.second, wt = adj[i].second;
           	//cout<<a<<" "<<b<<" "<<wt<<endl;
            if (find(a) != find(b))
            {
                merge(a, b);
                cnt++;
                ans += wt;
            }
            if (cnt == n - 1)
                return ans;
        }
        return ans;
    }
};