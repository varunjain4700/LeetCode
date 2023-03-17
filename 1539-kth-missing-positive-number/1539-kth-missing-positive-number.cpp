class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
            int diff = 0, total_diff = 0;
            int pre = 0;
            for (int i = 0; i < n; i++)
            {
                diff = arr[i] - pre - 1;
                if (total_diff + diff >= k)
                {
                    return pre + (k - total_diff);
                }
                pre = arr[i];
                total_diff += diff;
            }
            return arr[n - 1] + (k - total_diff);
        }
};