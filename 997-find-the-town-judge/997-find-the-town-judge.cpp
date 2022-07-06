class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {
            int m = trust.size();
            vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);
            for (int i = 0; i < m; i++)
            {
                indegree[trust[i][1]]++;
                outdegree[trust[i][0]]++;
            }
            int ans = -1;
            for (int i = 1; i <= n; i++)
            {
                if (indegree[i] == n - 1 && outdegree[i] == 0)
                {
                    if (ans != -1)
                        return -1;
                    ans = i;
                }
            }
            return ans;
        }
};