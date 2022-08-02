class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        }
    int maxEnvelopes(vector<vector < int>> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        vector<int> lis;
        for (int i = 0; i < n; i++)
        {
            if (lis.empty() || nums[i][1] > lis.back())
                lis.push_back(nums[i][1]);
            else
            {
                int idx = lower_bound(lis.begin(), lis.end(), nums[i][1]) - lis.begin();
                lis[idx] = nums[i][1];
            }
        }
        return lis.size();
    }
};