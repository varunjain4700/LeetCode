class Solution
{
    public:
        int minCostClimbingStairs(vector<int> &cost)
        {
            int n = cost.size();
            int prev2prev = cost[0];
            int prev = cost[1], ans = prev;
            for (int i = 2; i < n; i++)
            {
                ans = min(prev, prev2prev) + cost[i];
                prev2prev = prev;
                prev = ans;
            }
            return min(prev, prev2prev);
        }
};