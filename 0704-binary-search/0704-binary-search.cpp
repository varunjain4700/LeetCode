class Solution
{
    public:
        int binary_search(vector<int> &nums, int &target)
        {
            int low = 0, high = nums.size() - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return -1;
        }
    int search(vector<int> &nums, int target)
    {
        return binary_search(nums, target);
    }
};