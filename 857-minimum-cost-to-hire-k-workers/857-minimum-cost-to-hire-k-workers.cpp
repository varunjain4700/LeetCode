class Solution
{
    public:
        static bool cmp(vector<double> &a, vector<double> &b)
        {
            return a[0] < b[0];
        }
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = wage.size();
        vector<vector < double>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<double> temp = { (double) wage[i] / quality[i],
                (double) quality[i],
                (double) wage[i]
            };
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end(), cmp);
        priority_queue<double> pq;
        double sum = 0, ans = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i][1];
            pq.push(nums[i][1]);
        }
        ans = min(ans, nums[k - 1][0] *sum);
        for (int i = k; i < n; i++)
        {
            if (nums[i][1] < pq.top())
            {
                sum -= pq.top();
                pq.pop();
                sum += nums[i][1];
                ans = min(ans, sum *nums[i][0]);
                pq.push(nums[i][1]);
            }
        }
        return ans;
    }
};