class Solution
{
    public:
        vector < long long > dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src)
        {
            priority_queue<pair < long long, int>, vector< pair < long long, int>>, greater<pair < long long, int>>> pq;
            vector < long long > dist(n, 1e15);
            dist[src] = 0;
            pq.push({ 0,
                src });
            while (!pq.empty())
            {
                pair < long long, int> p = pq.top();
                pq.pop();
                long long w = p.first, v = p.second;
                if (dist[v] < w)	//imp:condition that optimises dijkstra(node is already processed so no need to check for its children)
                    continue;
                for (auto child: adj[v])
                {
                    if (w + child.second < dist[child.first])
                    {
                        dist[child.first] = w + child.second;
                        pq.push({ dist[child.first],
                            child.first });
                    }
                }
            }
            return dist;
        }
   	//finding the common point at which both src1 and src2 will meet and then traversing the rest of the distance to destination.Doing dijkstra for third time is the tricky part since we mave have more than one point at which src 1 and src2 meet and both have same(shortest) distance, so we need to to find shortest path from destination to rest of the nodes and find which will give the most optimal answer.
    long long minimumWeight(int n, vector<vector < int>> &edges, int src1, int src2, int dest)
    {
        vector<vector<pair<int, int>>> adj(n), rev(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({ edges[i][1],
                edges[i][2] });
            rev[edges[i][1]].push_back({ edges[i][0],	//reversed graph
                edges[i][2] });
        }
        vector < long long > dist1(n), dist2(n), dist3(n);
        dist1 = dijkstra(adj, n, src1);
        dist2 = dijkstra(adj, n, src2);
        dist3 = dijkstra(rev, n, dest);
        long long minm = 1e12;
        for (int i = 0; i < n; i++)
        {
            minm = min(minm, dist1[i] + dist2[i] + dist3[i]);
        }
        if (minm == 1e12)
            return -1;

        return minm;
    }
};