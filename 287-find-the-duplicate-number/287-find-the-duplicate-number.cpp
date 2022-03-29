class Solution
{
    public:
        int findDuplicate(vector<int> &nums)
        {
            int slow = nums[0], fast = nums[0];
            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            while (slow != fast);
            int start = nums[0];
            while (slow != start)
            {
                slow = nums[slow];
                start = nums[start];
            }
            return start;
        }
};