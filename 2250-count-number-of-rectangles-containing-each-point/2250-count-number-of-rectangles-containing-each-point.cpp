class Solution
{
    public:
        int solve(int l, int r, int target, vector<int> &nums)
        {
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (target <= nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            return l;
        }
    vector<int> countRectangles(vector<vector < int>> &rectangles, vector< vector< int>> &points)
    {
        int n = rectangles.size(), m = points.size();
        vector<vector < int>> lengths(101);
        for (int i = 0; i < n; i++)
        {
            lengths[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for (int i = 1; i <= 100; i++)
            sort(lengths[i].begin(), lengths[i].end());
        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            int ans = 0;
            for (int j = 1; j <= 100; j++)
            {
                if (j >= points[i][1])
                {
                   	// int idx = lower_bound(lengths[j].begin(), lengths[j].end(), points[i][0]) - lengths[j].begin();
                    int idx = solve(0, lengths[j].size(), points[i][0], lengths[j]);
                    ans += lengths[j].size() - idx;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};