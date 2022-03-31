class Solution
{
    public:
        bool solve(vector<int> &nums, int mid, int m)
        {
            int cnt = 1, sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > mid)
                    return false;
                sum += nums[i];
                if (sum > mid)
                {
                    sum = nums[i];
                    cnt++;
                }
            }
           	//cout << mid << " " << cnt << endl;
            if (cnt > m)
                return false;
            return true;
        }
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int low = 0, high = sum, mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (solve(nums, mid, m))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};