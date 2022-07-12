class Solution
{
    public:
        bool solve(int idx, vector<int> &subset, vector<int> &nums, int n, int k)
        {
            if (idx == n)
                return true;
            for (int i = 0; i < k; i++)
            {
                if (nums[idx] <= subset[i])
                {
                    subset[i] -= nums[idx];
                    if (solve(idx + 1, subset, nums, n, k))
                        return true;
                    subset[i] += nums[idx];
                }
                if (subset[i] == 0)
                    break;
            }
            return false;
        }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int> ());
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % k != 0)
            return false;
        vector<int> subset(k, sum / k);
        return solve(0, subset, nums, n, k);
    }
};