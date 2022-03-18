class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int n = cost.size();
            int amount = 0, total = 0, ans = 0, cap = 0;
            for (int i = 0; i < n; i++)
            {
                amount = gas[i] - cost[i];
                total += amount;
                if (total < 0)
                {
                    ans = (i + 1) % n;
                    total = 0;
                }
                cap += amount;
            }
            if (cap < 0)
                return -1;
            return ans;
        }
};