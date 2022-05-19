class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            int i = 0;
            while (i < n - 2)
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({ nums[i],
                            nums[j],
                            nums[k] });
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                        while (j < k && nums[k] == nums[k + 1])
                            k--;
                    }
                    else if (nums[i] + nums[j] + nums[k] < 0)
                        j++;
                    else
                        k--;
                }
                i++;
                while (i < n - 2 && nums[i] == nums[i - 1])
                    i++;
            }
            return ans;
        }
};