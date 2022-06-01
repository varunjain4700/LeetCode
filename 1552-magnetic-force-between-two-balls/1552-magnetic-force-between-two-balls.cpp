class Solution
{
    public:
        bool solve(int mid, int m, vector<int> &nums)
        {
            int total = 1, prev = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] - prev >= mid)
                {
                    total++;
                    prev = nums[i];
                }
            }
            if (total >= m)
                return true;
            return false;
        }
    int maxDistance(vector<int> &nums, int m)
    {
        sort(nums.begin(), nums.end());
        int low = 1, high = nums[nums.size() - 1];
        while (low < high)
        {
            int mid = (low + high + 1) / 2;
            if (solve(mid, m, nums))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};