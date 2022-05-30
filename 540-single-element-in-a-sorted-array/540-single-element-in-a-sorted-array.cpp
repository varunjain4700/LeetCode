class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int n = nums.size();
            int left = 0, right = n - 1;
            while (left <= right)
            {
                if (left == right)
                    return nums[left];
                int mid = (left + right) / 2;
                if (nums[mid] != nums[(mid - 1 + n) % n] && nums[mid] != nums[(mid + 1) % n])
                    return nums[mid];
                if (mid % 2 == 0)
                {
                    if (nums[mid] == nums[(mid - 1 + n) % n])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                else
                {
                    if (nums[mid] == nums[(mid - 1 + n) % n])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
            return 0;
        }
};