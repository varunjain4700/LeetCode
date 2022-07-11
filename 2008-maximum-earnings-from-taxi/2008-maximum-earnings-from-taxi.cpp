class Solution
{
    public:
        long long solve(int idx, vector<vector < int>> &jobs, int n, vector< int > &start_time, vector< long long > &dp)
        {
            if (idx == n)
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            long long ans = 0;
           	//don't do the current job
            ans = solve(idx + 1, jobs, n, start_time, dp);
           	//find the next job which can potentially take place if current job is selected and done
           	// auto pos = lower_bound(start_time.begin(), start_time.end(),
           	//     jobs[idx][1]) - start_time.begin();
            int low = idx + 1, high = n, end_time = jobs[idx][1];
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (start_time[mid] >= end_time)
                    high = mid;
                else
                    low = mid + 1;
            }
            ans = max(ans, jobs[idx][2] + jobs[idx][1] - jobs[idx][0] + solve(low, jobs, n, start_time, dp));
            return dp[idx] = ans;
        }
    long long maxTaxiEarnings(int m, vector<vector < int>> &rides)
    {
        int n = rides.size();
        sort(rides.begin(), rides.end());
        vector<int> start_time;
        for (int i = 0; i < n; i++)
            start_time.push_back(rides[i][0]);
        vector<long long> dp(n + 1, -1);
        return solve(0, rides, n, start_time, dp);
    }
};