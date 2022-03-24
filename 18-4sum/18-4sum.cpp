class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector < int>> res;
            for (int i = 0; i < n - 3; i++)
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    int sum = target - nums[i] - nums[j];
                    int k = j + 1, l = n - 1;
                    while (k < l)
                    {
                        if (nums[k] + nums[l] > sum)
                            l--;
                        else if (nums[k] + nums[l] < sum)
                            k++;
                        else
                        {
                            vector<int> ans = { nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            };
                            res.push_back(ans);
                            while (k < l && nums[k] == ans[2])
                                k++;
                            while (k < l && nums[l] == ans[3])
                                l--;
                        }
                    }
                    while (j + 1 < n && nums[j] == nums[j + 1])
                        j++;
                }
                while (i + 1 < n && nums[i] == nums[i + 1])
                    i++;
            }
            return res;
        }
};