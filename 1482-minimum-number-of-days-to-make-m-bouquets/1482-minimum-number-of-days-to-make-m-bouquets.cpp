class Solution
{
    public:
        int solve(vector<int> &bloomDay, int mid, int reqdBouquets, int k)
        {
            int sz = bloomDay.size(), bouquetSize = 0, totalBouquets = 0;
            for (int i = 0; i < sz; i++)
            {
                if (bloomDay[i] > mid)
                    bouquetSize = 0;
                else
                    bouquetSize++;
                if (bouquetSize == k)
                {
                    totalBouquets++;
                    bouquetSize = 0;
                }
            }
            if (totalBouquets >= reqdBouquets)
                return true;
            return false;
        }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if ((long long) m * k > n)
            return -1;
        int low = 1, high = 1e9;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (solve(bloomDay, mid, m, k))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};