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
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector< vector< int>> pairs)
    {
        int n = source.size();
        par.resize(n);
        size.resize(n);
        init(n);
        for (int i = 0; i < pairs.size(); i++)
        {
            if (find(pairs[i][0]) != find(pairs[i][1]))
                merge(pairs[i][0], pairs[i][1]);
        }
        vector<vector < int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            adj[find(i)].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            multiset<int> nums;
            for (int j = 0; j < adj[i].size(); j++)
            {
                nums.insert(source[adj[i][j]]);
            }
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (nums.find(target[adj[i][j]]) != nums.end())
                    nums.erase(nums.find(target[adj[i][j]]));
            }
            ans += nums.size();
        }
        return ans;
    }
};