class Solution
{
    public:
        int minDeletion(vector<int> &nums)
        {
            int n = nums.size(), ans = 0;
            for (int i = 0; i < n - 1; i += 2)
            {
                while (i < n - 1 && nums[i] == nums[i + 1])
                {
                    ans++;
                    i++;
                }
            }
            if ((n - ans) % 2 == 1)
                ans++;
            return ans;
        }
};