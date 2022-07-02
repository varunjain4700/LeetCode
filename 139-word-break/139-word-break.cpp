class Solution
{
    public:
        bool wordBreak(string str, vector<string> &dict)
        {
            int m = dict.size(), n = str.size();
            vector<bool> dp(n + 1, 0);
            unordered_set<string> words;
            for (int i = 0; i < m; i++)
            {
                words.insert(dict[i]);
            }
            dp[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (dp[j] == 1 && words.find(str.substr(j, i - j)) != words.end())
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            return dp[n];
        }
};