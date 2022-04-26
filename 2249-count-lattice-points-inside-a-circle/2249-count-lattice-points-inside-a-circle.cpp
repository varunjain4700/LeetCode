class Solution
{
    public:
        int countLatticePoints(vector<vector < int>> &circles)
        {
            int n = circles.size();
            int cnt = 0;
            for (int i = 0; i <= 200; i++)
            {
                for (int j = 0; j <= 200; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        int x = circles[k][0] - i, y = circles[k][1] - j, r = circles[k][2];
                        if (x *x + y *y - r * r <= 0)
                        {
                            cnt++;
                            break;
                        }
                    }
                }
            }
            return cnt;
        }
};