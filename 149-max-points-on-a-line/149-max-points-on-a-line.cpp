class Solution
{
    public:
        int maxPoints(vector<vector < int>> &points)
        {
            int n = points.size(), ans = 0;
            for (int i = 0; i < n; i++)
            {
                map<pair<int, int>, int> mp;
                int vertical=0;
                for (int j = 0; j < n; j++)
                {
                    if (points[i][0] == points[j][0])
                        vertical++;
                    else
                    {
                        int x = points[i][0] - points[j][0];
                        int y = points[i][1] - points[j][1];
                        int gcd = __gcd(x, y);
                        x /= gcd;
                        y /= gcd;
                        mp[
                        {
                            x,
                            y
                        }]++;
                    }
                }
                for (auto it: mp)
                {
                    ans = max(ans, it.second + 1);
                }
                ans=max(ans,vertical);
            }
            return ans;
        }
};