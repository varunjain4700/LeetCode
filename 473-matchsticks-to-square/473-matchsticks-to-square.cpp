class Solution
{
    public:
        bool solve(int idx, vector<int> &subset, vector<int> &nums, int n)
        {
            if (idx == n)
                return true;
            for (int i = 0; i < 4; i++)
            {
                if (nums[idx] <= subset[i])
                {
                    subset[i] -= nums[idx];
                    if (solve(idx + 1, subset, nums, n))
                        return true;
                    subset[i] += nums[idx];
                }
            }
            return false;
        }
    bool makesquare(vector<int> &nums)
    {
       	//partition array into 4 subsets such that sum of each subset=total_sum/4
        sort(nums.begin(), nums.end(), greater<int> ());	//(important)without this it will give TLE
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 4 != 0)
            return false;
        vector<int> subset(4, sum / 4);
        return solve(0, subset, nums, n);
    }
};