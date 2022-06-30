class Solution
{
    public:
        int minMoves2(vector<int> &nums)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int median = 0;
            if (n % 2 == 1)
                median = nums[n / 2];
            else
                median = (nums[n / 2 - 1] + nums[n / 2]) / 2;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += abs(nums[i] - median);
            }
            return ans;
        }
};