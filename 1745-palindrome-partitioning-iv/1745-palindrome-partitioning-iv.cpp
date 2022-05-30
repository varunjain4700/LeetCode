class Solution
{
    public:
        bool isP[2001][2001];
    bool check(string & str)
    {
        int n = str.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }
    int solve(int idx, int k, string &s, vector<vector < int>> &dp)
    {
        if (k == 0)
        {
            if (idx == s.size())
                return -1;
            else
                return 1e5;
        }
        if (idx == s.size())
            return 1e5;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans = 1e5;
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str += s[i];
            if (isP[idx][i])
            {
                ans = min(ans, 1 + solve(i + 1, k - 1, s, dp));
            }
        }
        return dp[idx][k] = ans;
    }
    bool checkPartitioning(string s)
    {
        memset(isP, 0, sizeof(isP));
        int n = s.size();
       	//Gives TLE if we check whether a string is a palindrome or not during recursion calls.So need some kind of pre computation.
       	//precomputing whether a substring is a palindrome or not
       	// below code taken from a solution
        for (int i = 0; i < s.size(); ++i)	//expanding from the centre technique used in Longest palindromic substring question too
        {
            isP[i][i] = true;
            int l = i - 1, r = i + 1;	//odd length palindromes
            while (l >= 0 && r < n && s[l] == s[r])
            {
                isP[l][r] = true;
                --l;
                ++r;
            }
            l = i;
            r = i + 1;	//even length palindromes
            while (l >= 0 && r < n && s[l] == s[r])
            {
                isP[l][r] = true;
                --l;
                ++r;
            }
        }
        if (check(s))
            return true;
        vector<vector < int>> dp(n, vector<int> (4, -1));
        int ans = solve(0, 3, s, dp);
       	//cout<<ans<<endl;
        if (ans == 2)
            return true;
        return false;
    }
};