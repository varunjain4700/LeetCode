class Solution
{
    public:
        vector<int> solve(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                while (nums[i] != nums[nums[i] - 1])
                    swap(nums[i], nums[nums[i] - 1]);
            }
            for (int i = 0; i < n; i++)
            {
                if (nums[i] != i + 1)
                    ans.push_back(i + 1);
            }
            return ans;
        }
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        return solve(nums);
       	// int n = nums.size();
       	// for (int i = 0; i < n; i++)
       	// {
       	//     int idx = abs(nums[i]) - 1;
       	//     if (nums[idx] > 0)
       	//         nums[idx] = -nums[idx];
       	// }
       	// vector<int> ans;
       	// for (int i = 0; i < n; i++)
       	// {
       	//     if (nums[i] > 0)
       	//         ans.push_back(i + 1);
       	// }
       	// return ans;
    }
};