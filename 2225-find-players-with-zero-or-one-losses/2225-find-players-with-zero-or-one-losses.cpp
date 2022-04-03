class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &nums)
        {
            int n = nums.size();
            vector<int> a1, a2;
            vector<int> win(1e5 + 5, 0), lose(1e5 + 5, 0);
            int maxm = 0;
            for (int i = 0; i < n; i++)
            {
                win[nums[i][0]]++;
                lose[nums[i][1]]++;
                maxm = max({ maxm,
                    nums[i][0],
                    nums[i][1] });
            }
            for (int i = 1; i <= maxm; i++)
            {
                if (win[i] > 0 && lose[i] == 0)
                    a1.push_back(i);
                if (lose[i] == 1)
                    a2.push_back(i);
            }
            vector<vector < int>> ans = { a1,
                a2
            };
            return ans;
        }
};