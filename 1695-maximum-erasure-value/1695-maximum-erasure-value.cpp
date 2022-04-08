class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            int n = nums.size();
            map<int, int> freq;
            int i = 0, j = 0;
            int ans = 0, sum = 0;
            while (j < n)
            {
                if (freq[nums[j]] == 1)
                {
                    while (freq[nums[j]] == 1)
                    {
                        freq[nums[i]]--;
                        sum -= nums[i];
                        i++;
                    }
                }
                freq[nums[j]]++;
                sum += nums[j];
                ans = max(ans, sum);
                j++;
            }
            return ans;
        }
};