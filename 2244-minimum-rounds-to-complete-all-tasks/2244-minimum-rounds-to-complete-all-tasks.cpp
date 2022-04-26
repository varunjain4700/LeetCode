class Solution
{
    public:
        int minimumRounds(vector<int> &tasks)
        {
            sort(tasks.begin(), tasks.end());
            int cnt = 0, ans = 0;
            for (int i = 0; i < tasks.size(); i++)
            {
                if (i > 0 && tasks[i] != tasks[i - 1])
                {
                    if (cnt == 1)
                        return -1;
                    ans += cnt / 3;
                    if (cnt % 3 != 0)
                        ans++;
                    cnt = 1;
                }
                else
                    cnt++;
            }
            if (cnt == 1)
                return -1;
            ans += cnt / 3;
            if (cnt % 3 != 0)
                ans++;
            return ans;
        }
};