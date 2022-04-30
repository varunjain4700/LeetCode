class Solution
{
    public:
       	//GRAPH PROBLEM srsly?????How can one know this without seeing this problem prior?
       	//Now,coming to the problem, we are taking each string as a node and making a weighted graph taking the weight as a given val(a/b). For ex:if given a/b=2 then making a--->b with weight 2 and also b--->a with weight 0.5. Now to find the answer to any query, we need to do a dfs traversal and multiply all the given weights.
        unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> vis;
    double ans = 1;
    bool dfs(string start, string end, double temp)
    {
        if (start == end && adj.find(start) != adj.end())
        {
            ans = temp;
            return true;
        }
        bool temp_ans = false;
        vis[start] = 1;
        for (auto child: adj[start])
        {
           	// cout<<child.first<<" ";
            if (!vis[child.first])
            {
                temp_ans = dfs(child.first, end, temp *child.second);
                if (temp_ans)
                    break;
            }
        }
        vis[start] = 0;
        return temp_ans;
    }

    vector<double> calcEquation(vector<vector < string>> &equations, vector< double > &val, vector< vector< string>> &queries)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({ equations[i][1],
                val[i] });
            adj[equations[i][1]].push_back({ equations[i][0],
                1 / val[i] });
            vis[equations[i][0]] = 0;
            vis[equations[i][1]] = 0;
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++)
        {
            ans = 1;
            bool temp = dfs(queries[i][0], queries[i][1], 1);
            if (!temp)
                ans = -1;
            res.push_back(ans);
        }
        return res;
    }
};