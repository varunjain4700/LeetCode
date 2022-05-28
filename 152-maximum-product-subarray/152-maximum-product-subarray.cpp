class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int n = nums.size();
            int minm, maxm, ans;
            ans = minm = maxm = nums[0];
            for (int i = 1; i < n; i++)
            {
                int temp = max({ maxm *nums[i],
                    minm *nums[i],
                    nums[i] });
                minm = min({ minm *nums[i],
                    maxm *nums[i],
                    nums[i] });
                maxm = temp;
                ans = max(ans, maxm);
            }
            return ans;
        }
};