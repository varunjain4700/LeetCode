class Solution
{
    public:
        int solve(int idx, vector<vector < int>> &events, vector< int > &start_time, vector< int > &dp)
        {
            if (idx == events.size())
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 0;
           	//not select an event 
            ans = solve(idx + 1, events, start_time, dp);

           	//or select the given event
            auto start = lower_bound(start_time.begin(), start_time.end(), events[idx][1]);
           	//next event with starting time greater than ending time of current event can only be chosen
            int nxt_event = start - start_time.begin();
            ans = max(ans, events[idx][2] + solve(nxt_event, events, start_time, dp));

            return dp[idx] = ans;
        }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {
        int n = startTime.size();
        vector<vector < int>> events;
        for (int i = 0; i < n; i++)
        {
            events.push_back({ startTime[i],
                endTime[i],
                profit[i] });
        }
        sort(events.begin(), events.end());
        vector<int> dp(n + 1, -1);
        vector<int> start_time(n, 0);
        for (int i = 0; i < n; i++)
            start_time[i] = events[i][0];
        return solve(0, events, start_time, dp);
    }
};