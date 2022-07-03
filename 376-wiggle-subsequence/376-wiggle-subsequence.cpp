class Solution
{
    public:
        int wiggleMaxLength(vector<int> &nums)
        {
            int sign = 0, ans = 1;
           	// sign=1 indicates increasing sequence(diff>0) and -1 means decreasing sequence(diff < 0)
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > nums[i - 1] && sign != 1)
                {
                    sign = 1;
                    ans++;
                }
                else if (nums[i - 1] > nums[i] && sign != -1)
                {
                    sign = -1;
                    ans++;
                }
            }
            return ans;
        }
};