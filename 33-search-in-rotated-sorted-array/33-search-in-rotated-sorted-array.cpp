class Solution
{
    public:
        int binary_search(int l, int r, vector<int> &nums, int target)
        {
            int low = l, high = r;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                    return mid;
                if (nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return -1;
        }
    int find_minm(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[high])
                return low;
            int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return mid;
            if (nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
    int search(vector<int> &nums, int target)
    {
        int minm = find_minm(nums);
        if (target == nums[minm])
            return minm;
        int ans = binary_search(0, minm - 1, nums, target);
        if (ans == -1)
        {
            return binary_search(minm + 1, nums.size() - 1, nums, target);
        }
        return ans;
    }
};