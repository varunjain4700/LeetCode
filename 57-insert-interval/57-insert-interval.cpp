class Solution
{
    public:
        vector<vector < int>> insert(vector<vector < int>> &intervals, vector< int > &new_in)
        {
            int n = intervals.size();
            bool flag = 0;
            if (intervals.empty() || new_in[0] <= intervals[0][0])
                intervals.insert(intervals.begin(), new_in);
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (i + 1 < n && new_in[0] >= intervals[i][0] && new_in[0] <= intervals[i + 1][0])
                    {
                        intervals.insert(intervals.begin() + i + 1, new_in);
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    intervals.push_back(new_in);
            }
            int start = intervals[0][0], end = intervals[0][1];
            vector<vector < int>> res;
            for (int i = 1; i <= n; i++)
            {
                if (intervals[i][0] > end)
                {
                    res.push_back({ start,
                        end });
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
                else
                    end = max(end, intervals[i][1]);
            }
            res.push_back({ start,
                end });
            return res;
        }
};