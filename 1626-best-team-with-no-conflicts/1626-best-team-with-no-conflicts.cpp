class Solution
{
    public:
        int bestTeamScore(vector<int> &scores, vector<int> &ages)
        {
            int n = scores.size();
            vector<pair<int, int>> v;
            for (int i = 0; i < n; i++)
                v.push_back({ ages[i],scores[i] });
            sort(v.begin(), v.end());
            vector<int> dp(n, 0);
            int ans=0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (v[i].second >= v[j].second)
                        dp[i] = max(dp[i], dp[j]);
                }
                dp[i] += v[i].second;
                ans=max(ans,dp[i]);
            }
            return ans;
        }
};