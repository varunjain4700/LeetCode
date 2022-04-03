class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int n = nums.size();
            for (int i = n - 2; i >= 0; i--)
            {
                int minm = 101, idx = -1;
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] > nums[i] && nums[j] < minm)
                    {
                        minm = nums[j];
                        idx = j;
                    }
                }
                if (minm != 101)
                {
                    swap(nums[i], nums[idx]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
            sort(nums.begin(), nums.end());
        }
};