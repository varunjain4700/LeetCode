class Solution
{
    public:
        int solve(vector<int> &time, int trips, long long mid)
        {
            int n = time.size();
            long long total = 0;
            for (int i = 0; i < n; i++)
            {
                total += mid / time[i];
            }
            if (total >= trips)
                return true;
            return false;
        }
    long long minimumTime(vector<int> &time, int trips)
    {
        sort(time.begin(), time.end());
        long long low = 1;
        long long high = (long long) time[0] *trips;
        long long mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (solve(time, trips, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};