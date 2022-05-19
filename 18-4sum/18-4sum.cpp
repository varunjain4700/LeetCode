class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            int i = 0;
            while (i < n - 3)
            {
                int j = i + 1;
                while (j < n - 2)
                {
                    int sum = target - nums[i] - nums[j];
                    int k = j + 1, l = n - 1;
                    while (k < l)
                    {
                        if (nums[k] + nums[l] == sum)
                        {
                            ans.push_back({ nums[i],
                                nums[j],
                                nums[k],
                                nums[l] });
                            k++;
                            l--;
                            while (k < l && nums[k] == nums[k - 1])
                                k++;
                            while (k < l && nums[l] == nums[l + 1])
                                l--;
                        }
                        else if (nums[k] + nums[l] < sum)
                            k++;
                        else
                            l--;
                    }
                    j++;
                    while (j < n - 2 && nums[j] == nums[j - 1])
                        j++;
                }
                i++;
                while (i < n - 3 && nums[i] == nums[i - 1])
                    i++;
            }
            return ans;
        }
};