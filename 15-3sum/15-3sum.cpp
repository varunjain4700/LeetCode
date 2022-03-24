class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            int n = nums.size();
            vector<vector < int>> res;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i++)
            {
                int sum = -nums[i], j = i + 1, k = n - 1;
                while (j < k)
                {
                    if (nums[j] + nums[k] > sum)
                        k--;
                    else if (nums[j] + nums[k] < sum)
                        j++;
                    else
                    {
                        vector<int> temp = { nums[i],nums[j],nums[k]};
                        res.push_back(temp);

                        while (j < k && nums[j] == temp[1])	//handling duplicates of second num
                            j++;
                        while (j < k && nums[k] == temp[2])	//handling duplicates of third num
                            k--;
                    }
                }
                while (i+1 < n && nums[i] == nums[i + 1])	//handling duplicates of first num
                    i++;
            }
            return res;
        }
};