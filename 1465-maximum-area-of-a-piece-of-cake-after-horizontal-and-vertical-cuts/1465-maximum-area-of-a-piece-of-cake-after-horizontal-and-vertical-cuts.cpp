class Solution
{
    public:
        int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
        {
            horizontalCuts.push_back(h);
            verticalCuts.push_back(w);
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());
            int n = horizontalCuts.size(), m = verticalCuts.size();
            long long h_max = horizontalCuts[0], v_max = verticalCuts[0];
            long long mod = 1e9 + 7;
            for (int i = 1; i < n; i++)
            {
                h_max = max(h_max, (long long)(horizontalCuts[i] - horizontalCuts[i - 1]));
            }
            for (int i = 1; i < m; i++)
            {
                v_max = max(v_max, (long long)(verticalCuts[i] - verticalCuts[i - 1]));
            }
            return (h_max *v_max) % mod;
        }
};