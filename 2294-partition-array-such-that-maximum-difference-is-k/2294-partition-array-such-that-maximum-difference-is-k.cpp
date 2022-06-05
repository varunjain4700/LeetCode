class Solution
{
    public:
        int partitionArray(vector<int> &nums, int k)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int ans = 1, prev = nums[0];
            for (int i = 1; i < n; i++)
            {
                if (nums[i] - prev > k)
                {
                    ans++;
                    prev = nums[i];
                }
            }
            return ans;
        }
};