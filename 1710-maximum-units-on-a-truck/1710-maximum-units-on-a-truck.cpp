class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            return a[1] > b[1];
        }
    int maximumUnits(vector<vector < int>> &types, int truckSize)
    {
        sort(types.begin(), types.end(), cmp);
        int n = types.size(), sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + types[i][0] <= truckSize)
            {
                sum += types[i][0];
                ans += types[i][0] *types[i][1];
            }
            else
            {
                ans += (truckSize - sum) *(types[i][1]);
                sum = truckSize;
                break;
            }
        }
        return ans;
    }
};