class Solution
{
    public:
        vector<int> cnt;
    void sort(int low, int high, vector<pair<int, int>> &nums)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            sort(low, mid, nums);
            sort(mid + 1, high, nums);
            merge(low, high, nums);
        }
    }
    void merge(int low, int high, vector<pair<int, int>> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> res(high - low + 1);
        int mid = (low + high) / 2;
        int i = low, j = mid + 1, k = 0;
        int smallerToRight = 0;
        while (i <= mid && j <= high)
        {
            if (nums[i].first <= nums[j].first)
            {
                res[k].first = nums[i].first;
                res[k].second = nums[i].second;
                cnt[nums[i].second] += smallerToRight;
                k++;
                i++;
            }
            else
            {
                smallerToRight++;
                res[k].first = nums[j].first;
                res[k].second = nums[j].second;
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            res[k].first = nums[i].first;
            res[k].second = nums[i].second;
            cnt[nums[i].second] += smallerToRight;
            k++;
            i++;
        }
        while (j <= high)
        {
            res[k].first = nums[j].first;
            res[k].second = nums[j].second;
            k++;
            j++;
        }
        k = 0;
        for (int i = low; i <= high; i++)
        {
            nums[i].first = res[k].first;
            nums[i].second = res[k].second;
            k++;
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> new_nums;
        cnt.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            new_nums.push_back({ nums[i],
                i });
        }
        sort(0, n - 1, new_nums);
        return cnt;
    }
};