class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int n = nums.size();
            vector<int> res;
            int low = 0, high = n - 1, ans = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (target == nums[mid])
                {
                    ans = mid;
                    high = mid - 1;
                }
                else if (target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            res.push_back(ans);
            ans = -1;
            low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (target == nums[mid])
                {
                    ans = mid;
                    low = mid + 1;
                }
                else if (target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            res.push_back(ans);
            return res;
        }
};