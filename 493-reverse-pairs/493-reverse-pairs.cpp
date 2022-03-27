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
        int mid = (low + high) / 2;
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high)
        {
            if ((long long) 2 *nums[j] < (long long) nums[i])
            {
                cnt += (mid - i + 1);
                ++j;
            }
            else
            {
                ++i;
            }
        }
        i = low, j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (nums[j] < nums[i])
            {
                res[k] = nums[j];
                ++k;
                ++j;
            }
            else
            {
                res[k] = nums[i];
                ++k;
                ++i;
            }
        }
        while (j <= high)
        {
            res[k] = nums[j];
            ++k;
            ++j;
        }
        while (i <= mid)
        {
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
           // cout << nums[i] << " ";
        }
        //cout << endl;
       	// sort(nums.begin() + low, nums.begin() + high + 1);
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        cnt = 0;
        sortArray(nums, 0, n - 1);
        return cnt;
    }
};