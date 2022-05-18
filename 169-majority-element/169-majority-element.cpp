class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int n = nums.size();
            int cnt = 0, ans = 2e9;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == ans)
                {
                    cnt++;
                }
                else
                {
                    if (cnt == 0)
                    {
                        ans = nums[i];
                        cnt = 1;
                    }
                    else
                        cnt--;
                }
            }
            return ans;
        }
};