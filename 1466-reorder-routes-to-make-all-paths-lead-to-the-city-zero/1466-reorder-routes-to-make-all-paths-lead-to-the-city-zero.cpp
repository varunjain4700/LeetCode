class Solution
{
    public:
       	//adding artificial edges in order to make the graph undirected(so that we can traverse the whole graph) and to differentiate between original and artificial edge,we are using a boolean value.All we want is that there should be no edge from a parent to its children(since such nodes will not be able to reach the root node 0);
        int minReorder(int n, vector<vector < int>> &connections)
        {
            vector<vector<pair<int, int>>> adj(n);
            for (int i = 0; i < connections.size(); i++)
            {
                adj[connections[i][0]].push_back({ connections[i][1],
                    1 });
                adj[connections[i][1]].push_back({ connections[i][0],
                    0 });
            }
            queue<int> q;
            q.push(0);
            int result = 0;
            vector<bool> vis(n, 0);
            vis[0] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto child: adj[node])
                {
                    if (!vis[child.first])
                    {
                        vis[child.first] = 1;
                        q.push(child.first);
                        result += child.second;
                    }
                }
            }
            return result;
        }
};