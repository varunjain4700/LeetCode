class Solution
{
    public:
        int solve(vector<int> &nums, int k)	//subarrays with atmost k odd numbers
    {
        int n = nums.size();
        int i = 0, j = 0, cnt = 0;
        int ans = 0;
        while (i < n)
        {
            if (nums[i] % 2 == 1)
                cnt++;
            while (cnt > k)
            {
                if (nums[j] % 2 == 1)
                    cnt--;
                j++;
            }
            ans += i - j + 1;
            i++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};