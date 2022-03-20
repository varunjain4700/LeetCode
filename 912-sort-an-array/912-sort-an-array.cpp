class Solution
{
    public:
        void mergesort(vector<int> &nums, int start, int end)
        {
            if (start < end)
            {
                int mid = (start + end) / 2;
                mergesort(nums, start, mid);
                mergesort(nums, mid + 1, end);
                merge(nums, start, mid, end);
            }
        }
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        vector<int> res;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (nums[i] < nums[j])
            {
                res.push_back(nums[i]);
                i++;
            }
            else
            {
                res.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            res.push_back(nums[i]);
            i++;
        }
        while (j <= r)
        {
            res.push_back(nums[j]);
            j++;
        }
        int k = 0;
        for (int i = l; i <= r; i++)
        {
            nums[i] = res[k++];
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};