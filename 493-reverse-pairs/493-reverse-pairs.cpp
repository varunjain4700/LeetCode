class Solution
{
    public:
        int cnt = 0;
    void sortArray(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            sortArray(nums, low, mid);
            sortArray(nums, mid + 1, high);
            merge(nums, low, high);
        }
    }
    void merge(vector<int> &nums, int low, int high)
    {
        vector<int> res(high - low + 1);
        int smallerToRight = 0;
        int mid = (low + high) / 2;
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high)
        {
            if ((long long) 2 *nums[j] < (long long) nums[i])
            {
                smallerToRight++;
                res[k] = nums[j];
                ++k;
                ++j;
            }
            else
            {
                cnt += smallerToRight;
                res[k] = nums[i];
                ++k;
                ++i;
            }
        }
        while (j <= high)
        {
            smallerToRight++;
            res[k] = nums[j];
            ++k;
            ++j;
        }
        while (i <= mid)
        {
            cnt += smallerToRight;
            res[k] = nums[i];
            ++k;
            ++i;
        }
       	// cout << low << " " << high << endl;
       	// cout << cnt << endl;
        k = 0;
        for (int i = low; i <= high; i++)
        {
            nums[i] = res[k++];
        }
        sort(nums.begin() + low, nums.begin() + high + 1);
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        cnt = 0;
        sortArray(nums, 0, n - 1);
        return cnt;
    }
};