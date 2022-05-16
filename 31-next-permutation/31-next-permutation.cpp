class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int n = nums.size();
            int i, idx2, idx1 = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] < nums[i] && j > idx1)
                    {
                        idx1 = max(idx1, j);
                        idx2 = i;
                        break;
                    }
                }
            }
            if (idx1 == -1)
            {
                sort(nums.begin(), nums.end());
                return;
            }
            swap(nums[idx1], nums[idx2]);
            sort(nums.begin() + idx1 + 1, nums.end());
        }
};