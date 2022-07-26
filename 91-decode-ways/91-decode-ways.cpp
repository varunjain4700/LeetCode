class Solution
{
    public:
        int solve(int idx, string &s, unordered_map<string, int> &mp, vector<int> &dp)
        {
            if (idx == s.size())
                return 1;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 0;
            string temp = "";
            temp += s[idx];
            if (mp.find(temp) != mp.end())
                ans += solve(idx + 1, s, mp, dp);
            if (idx + 1 < s.size())
            {
                temp += s[idx + 1];
                if (mp.find(temp) != mp.end())
                    ans += solve(idx + 2, s, mp, dp);
            }
            return dp[idx] = ans;
        }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        unordered_map<string, int> mp;
        for (int i = 1; i <= 26; i++)
        {
            string temp = to_string(i);
            mp[temp]++;
        }
        return solve(0, s, mp, dp);
    }
};