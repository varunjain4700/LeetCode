class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int n = nums.size();
            int idx1 = -1, idx2;
            for (int i = n - 1; i >= 1; i--)
            {
                if (nums[i - 1] < nums[i])
                {
                    idx1 = i - 1;
                    break;
                }
            }
            if (idx1 == -1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
            for (int i = n - 1; i >= 0;i--)
            {
                if (nums[i] > nums[idx1])
                {
                    idx2 = i;
                    break;
                }
            }
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin() + idx1+1, nums.end());

           	//O(n^2) approach

           	// int n = nums.size();
           	// int i, idx2, idx1 = -1;
           	// for (int i = n - 1; i >= 0; i--)
           	// {
           	//     for (int j = i - 1; j >= 0; j--)
           	//     {
           	//         if (nums[j] < nums[i] && j > idx1)
           	//         {
           	//             idx1 = max(idx1, j);
           	//             idx2 = i;
           	//             break;
           	//         }
           	//     }
           	// }
           	// if (idx1 == -1)
           	// {
           	//     sort(nums.begin(), nums.end());
           	//     return;
           	// }
           	// swap(nums[idx1], nums[idx2]);
           	// sort(nums.begin() + idx1 + 1, nums.end());
        }
};