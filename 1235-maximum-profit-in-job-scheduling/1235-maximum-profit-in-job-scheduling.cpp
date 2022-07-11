class Solution
{
    public:
        int solve(int idx, vector<vector < int>> &jobs, int n, vector< int > &start_time, vector< int > &dp)
        {
            if (idx == n)
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 0;
           	//don't do the current job
            ans = solve(idx + 1, jobs, n, start_time, dp);
           	//find the next job which can potentially take place if current job is selected and done
            auto pos = lower_bound(start_time.begin(), start_time.end(),
                jobs[idx][1]) - start_time.begin();
            ans = max(ans, jobs[idx][2] + solve(pos, jobs, n, start_time, dp));
            return dp[idx] = ans;
        }
    int jobScheduling(vector<int> &start, vector<int> &end, vector< int > &profit)
    {
        vector<vector < int>> jobs;
        int n = start.size();
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({ start[i],
                end[i],
                profit[i] });
        }
        sort(jobs.begin(), jobs.end());
        vector<int> start_time;
        for (int i = 0; i < n; i++)
            start_time.push_back(jobs[i][0]);
        vector<int> dp(n + 1, -1);
        return solve(0, jobs, n, start_time, dp);
    }
};