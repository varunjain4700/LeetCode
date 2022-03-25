class Solution
{
    public:
        int twoCitySchedCost(vector<vector < int>> &costs)
        {
            int n = costs.size();
            vector<pair<int, pair<int, int>>> v;
            for (int i = 0; i < n; i++)
            {
                v.push_back({ costs[i][0] - costs[i][1],
                    {
                        costs[i][0],
                        costs[i][1]
                    } });
            }
            sort(v.begin(), v.end());
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (i < n / 2)
                    ans += v[i].second.first;
                else
                    ans += v[i].second.second;
            }
            return ans;
        }
};