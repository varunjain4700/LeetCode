class Solution
{
    public:
        int bs(vector<int> &nums, int low, int high, int target)
        {
            int start = low, end = high, mid;
            while (start <= end)
            {
               	//cout<<start<<" "<<end<<endl;
                mid = (start + end) / 2;
                if (target == nums[mid])
                    return mid;
                else if (target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            return -1;
        }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        int minm = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
           	//cout<<low<<" "<<high<<endl;
            if (nums[low] <= nums[high])
            {
                minm = low;
                break;
            }
            int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                minm = mid;
                break;
            }
            if (nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
       	// cout<<minm<<endl;
        int idx = bs(nums, 0, minm - 1, target);
        if (idx == -1)
            idx = bs(nums, minm, n - 1, target);
        return idx;
    }
};