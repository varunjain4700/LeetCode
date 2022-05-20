class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int n = nums.size();
            int idx = 0, k = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == 0 || nums[i] != nums[i - 1])
                {
                    nums[idx] = nums[i];
                    idx++;
                    k++;
                }
            }
            return idx;
        }
};