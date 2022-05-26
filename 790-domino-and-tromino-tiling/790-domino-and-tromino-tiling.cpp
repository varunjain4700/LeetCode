class Solution
{
    public:
       	//Check this solution for understanding:https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116612/Easy-to-understand-O(n)-solution-with-Drawing-Picture-Explanation!
        int numTilings(int n)
        {
            vector < long long > dp1(n + 3, 0), dp2(n + 3, 0);
            dp1[0] = 0, dp1[1] = 1, dp1[2] = 2;
            dp2[0] = 0, dp2[1] = 1;
            dp2[2] = 2;
            long long mod = 1e9 + 7;
            for (int i = 3; i <= n; i++)
            {
                dp2[i] = (dp1[i - 1] + dp2[i - 1]) % mod;
                dp1[i] = (dp1[i - 1] + dp1[i - 2] + 2 *dp2[i - 2]) % mod;
            }
            return dp1[n];
        }
};