class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            int n = intervals.size();
            sort(intervals.begin(), intervals.end());
            int start_time = intervals[0][0], end_time = intervals[0][1];
            vector<vector < int>> ans;
            for (int i = 1; i < n; i++)
            {
                if (intervals[i][0] <= end_time)
                {
                    end_time = max(end_time, intervals[i][1]);
                }
                else
                {
                    ans.push_back({ start_time,
                        end_time });
                    start_time = intervals[i][0];
                    end_time = intervals[i][1];
                }
            }
            ans.push_back({ start_time,
                end_time });
            return ans;
        }
};