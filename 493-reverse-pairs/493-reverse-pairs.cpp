class Solution
{
    public:
        int cnt = 0;
    void sort_arr(int low, int high, vector<int> &nums)
    {
        int mid = (low + high) / 2;
        if (low < high)
        {
            sort_arr(low, mid, nums);
            sort_arr(mid + 1, high, nums);
            merge(low, high, nums);
        }
    }
    void merge(int low, int high, vector<int> &nums)
    {
        vector<int> ans(high - low + 1, 0);
        int mid = (low + high) / 2;
        int i = low, j = mid + 1, k = 0;
        int smallerToRight = 0;
        while (i <= mid && j <= high)
        {
            if (nums[i] > (long long) 2 *nums[j])
            {
                smallerToRight++;
                j++;
            }
            else
            {
                cnt += smallerToRight;
                i++;
            }
        }
        while (i <= mid)
        {
            cnt += smallerToRight;
            i++;
        }
        i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high)
        {
            if (nums[i] > nums[j])
                ans[k++] = nums[j++];
            else
                ans[k++] = nums[i++];
        }
        while (i <= mid)
        {
            ans[k++] = nums[i++];
        }
        while (j <= high)
        {
            ans[k++] = nums[j++];
        }
        k = 0;
        for (int i = low; i <= high; i++)
            nums[i] = ans[k++];
    }
    int reversePairs(vector<int> &nums)
    {
        cnt = 0;
        sort_arr(0, nums.size() - 1, nums);
        return cnt;
    }
};