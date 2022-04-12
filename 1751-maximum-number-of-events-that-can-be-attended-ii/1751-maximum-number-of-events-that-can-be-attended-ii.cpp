class Solution
{
    public:
        long long solve(int idx, int k, vector<vector < int>> &events, vector< int > &start_time, vector< vector<long long>> &dp)
        {
            if (idx == events.size() || k <= 0)
                return 0;
            if (dp[idx][k] != -1)
                return dp[idx][k];
            long long ans = 0;
           	//not select an event 
            ans = solve(idx + 1, k, events, start_time, dp);

           	//or select the given event
            auto start = lower_bound(start_time.begin(), start_time.end(), events[idx][1] + 1);
           	//next event with starting time greater than ending time of current event can only be chosen
            int nxt_event = start - start_time.begin();
            ans = max(ans, events[idx][2] + solve(nxt_event, k - 1, events, start_time, dp));

            return dp[idx][k] = ans;
        }
    int maxValue(vector<vector < int>> &events, int k)
    {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector < long long>> dp(n + 1, vector<long long> (k + 1, -1));
        vector<int> start_time(n, 0);
        for (int i = 0; i < n; i++)
            start_time[i] = events[i][0];
        return solve(0, k, events, start_time, dp);
    }
};