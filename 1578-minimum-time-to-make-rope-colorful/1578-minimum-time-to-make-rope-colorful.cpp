class Solution
{
    public:
        int minCost(string colors, vector<int> &time)
        {
            int n = colors.size();
            int cnt = 1, ans = 0, sum = time[0], maxm = sum;
            for (int i = 1; i < n; i++)
            {
                if (colors[i] != colors[i - 1])
                {
                    if (cnt > 1)
                        ans += sum - maxm;
                    maxm = sum = cnt = 0;
                }
                sum += time[i];
                cnt++;
                maxm = max(maxm, time[i]);
            }
            if (cnt > 1)
                ans += sum - maxm;
            return ans;
        }
};