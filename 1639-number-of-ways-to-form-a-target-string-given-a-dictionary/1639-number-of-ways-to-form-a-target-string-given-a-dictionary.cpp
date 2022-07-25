class Solution
{
    public:
        long long dp[1001][1001];
    int mod = 1e9 + 7;
    long long solve(int i, int j, vector<string> &words, string &target, map<pair<int, char>, int> &freq)
    {
        if (i == target.size())
            return 1;
        if (j == words[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long ans = 0;
        char ch = target[i];
        ans += freq[
        {
            j,
            ch
        }] *solve(i + 1, j + 1, words, target, freq);	//add the contribution of number of characters that match with target's ith character
        ans %= mod;
        ans += solve(i, j + 1, words, target, freq);	//or move forward and in future may the charcters match
        ans %= mod;
        return dp[i][j] = ans;
    }
    int numWays(vector<string> &words, string target)
    {
        memset(dp, -1, sizeof(dp));
        map<pair<int, char>, int> freq;
        for (int i = 0; i < words[0].size(); i++)	//preprocess the frequencies 
        {
            for (int j = 0; j < words.size(); j++)
            {
                freq[
                {
                    i,
                    words[j][i]
                }]++;
            }
        }
        return solve(0, 0, words, target, freq);
    }
};