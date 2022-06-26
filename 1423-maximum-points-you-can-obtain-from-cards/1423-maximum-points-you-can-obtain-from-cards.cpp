class Solution
{
    public:
        int maxScore(vector<int> &cards, int k)
        {
           	// int n = cards.size();
           	// vector<int> pre(n + 1, 0), suff(n + 1, 0);
           	// pre[0] = cards[0];
           	// for (int i = 1; i < n; i++)
           	//     pre[i] = pre[i - 1] + cards[i];
           	// suff[n - 1] = cards[n - 1];
           	// for (int i = n - 2; i >= 0; i--)
           	//     suff[i] = cards[i] + suff[i + 1];
           	// int ans = suff[n - k];
           	// for (int i = 0; i < k; i++)
           	//     ans = max(ans, pre[i] + suff[n - k + 1 + i]);
           	// return ans;

            int n = cards.size();
            int i = 0, j = 0, ans = INT_MAX, sum = 0, total = 0;
            while (j < n)
            {
                sum += cards[j];
                total += cards[j];
                if (j - i + 1 == n - k)
                {
                    ans = min(ans, sum);
                    sum -= cards[i];
                    i++;
                }
                j++;
            }
            if(k==n)
                return total;
            return total - ans;
        }
};