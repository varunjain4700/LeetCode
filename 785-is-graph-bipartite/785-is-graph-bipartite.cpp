class Solution
{
    public:
        vector<bool> vis, col;
    bool bad;
    void dfs(int src, bool color, vector<vector < int>> &graph)
    {
        vis[src] = 1;
        col[src] = color;
        for (auto child: graph[src])
        {
            if (!vis[child])
                dfs(child, !color, graph);
            else
            {
                if (col[child] == color)
                    bad = true;
            }
        }
    }
    bool isBipartite(vector<vector < int>> &graph)
    {
        bad = false;
        vis.resize(graph.size(), 0);
        col.resize(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
                dfs(i, 0, graph);
        }
        if (bad)
            return false;
        return true;
    }
};