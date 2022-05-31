class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int n = nums.size();
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[low] <= nums[high])
                    return nums[low];
                int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
                if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                    return nums[mid];
                if (nums[low] <= nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return 0;
        }
};