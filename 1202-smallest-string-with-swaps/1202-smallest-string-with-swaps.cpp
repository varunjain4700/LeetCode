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

    string smallestStringWithSwaps(string s, vector<vector < int>> &pairs)
    {
        par.resize(s.size());
        size.resize(s.size());
        init(s.size());
        for (int i = 0; i < pairs.size(); i++)
        {
            if (find(pairs[i][0]) != find(pairs[i][1]))
                merge(pairs[i][0], pairs[i][1]);
        }
        vector<vector < int>> adj(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            adj[find(i)].push_back(i);
        }
        for (int i = 0; i < s.size(); i++)
        {
            vector<char> temp;
            for (int j = 0; j < adj[i].size(); j++)
            {
                temp.push_back(s[adj[i][j]]);
            }
            sort(temp.begin(), temp.end());
            for (int j = 0; j < adj[i].size(); j++)
                s[adj[i][j]] = temp[j];
        }
        return s;
    }
};