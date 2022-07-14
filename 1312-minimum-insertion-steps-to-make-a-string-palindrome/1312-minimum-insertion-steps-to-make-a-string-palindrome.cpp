class Solution
{
    public:
        int minInsertions(string s)
        {
            int n = s.size();
            string t;
            for (int i = n - 1; i >= 0; i--)
                t += s[i];
           	// vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
            vector<int> curr(n + 1, 0), pre(n + 1, 0);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (s[i - 1] == t[j - 1])
                        curr[j] = pre[j - 1] + 1;
                    else
                        curr[j] = max(pre[j], curr[j - 1]);
                }
                pre = curr;
            }
            return n - pre[n];
        }
};