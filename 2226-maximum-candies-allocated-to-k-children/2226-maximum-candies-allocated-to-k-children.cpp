class Solution
{
    public:
        bool solve(vector<int> &candies, long long k, long long mid)
        {
            long long total = 0;
            for (int i = 0; i < candies.size(); i++)
            {
                total += candies[i] / mid;
            }
            if (total >= k)
                return true;
            return false;
        }
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long low = 0, high = 1e7, mid;
        while (low < high)
        {
            mid = (low + high + 1) / 2;
            if (solve(candies, k, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};