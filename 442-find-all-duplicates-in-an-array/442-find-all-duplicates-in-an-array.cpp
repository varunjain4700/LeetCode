class Solution
{
    public:
        vector<int> findDuplicates(vector<int> &nums)
        {
           	//negating every element in the given array(just a way to keep frequency as we can't use additional space),if the given element is already negative it means it is occuring twice
            int n = nums.size();
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                int idx = abs(nums[i]) - 1;
                if (nums[idx] < 0)
                    res.push_back(idx + 1);
                nums[idx] = -nums[idx];
            }

            return res;
        }
};