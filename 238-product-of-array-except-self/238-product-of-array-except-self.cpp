class Solution
{
    public:
       	//First tell the O(n) space approach using separate arrays to store prefix and suffix product and then optimise it further if asked.
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> res(n, 1);
            for (int i = 1; i < n; i++)
            {
                res[i] = res[i - 1] *nums[i - 1];
            }
            int suff_product = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                res[i] *= suff_product;
                suff_product *= nums[i];
            }
            return res;
        }
};