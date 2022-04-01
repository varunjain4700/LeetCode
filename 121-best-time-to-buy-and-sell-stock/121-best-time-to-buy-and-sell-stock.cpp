class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size(), ans = 0;
            vector<int> maxm(n, 0);
            for (int i = n - 2; i >= 0; i--)
                maxm[i] = max(maxm[i + 1], prices[i + 1]);
            for (int i = 0; i < n; i++)
            {
                ans = max(ans, maxm[i] - prices[i]);
            }
            return ans;
        }
};