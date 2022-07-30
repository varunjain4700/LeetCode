class Solution
{
    public:
    //Why tf you don't revise questions -_-
        int maxFrequency(vector<int> &nums, int k)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            long long i = 0, j = 0, max_freq = 1, sum = 0;
            int element = 0;
            while (j < n)
            {
                sum += nums[j];
                while (sum + k < (long long)(j - i + 1) *nums[j])
                {
                    sum -= nums[i];
                    i++;
                }
                if (j - i + 1 > max_freq)
                {
                    max_freq = j - i + 1;
                    element = nums[j];
                }
               	// ans = max(ans, j - i + 1);
                j++;
            }
            cout << max_freq << " " << element << endl;
            return max_freq;
        }
};