class Solution
{
    public:
        int solve(vector<int> &nums, int val)
        {
            int n = nums.size();
            int cnt = 0, i = 0, j = 0;
            while (i < n)
            {
                if (nums[i] != val)
                {
                    j = i + 1;
                }
                cnt += i - j + 1;
                i++;
            }
            return cnt;
        }
    int numSubmat(vector<vector < int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<int> temp(n, 0);
        for (int i = 0; i < m; i++)
        {
            temp.assign(n,0);
            int val = 0;
            for (int j = i; j < m; j++)
            {
                val++;
                for (int k = 0; k < n; k++)
                {
                    temp[k] += mat[j][k];
                }
                ans += solve(temp, val);
            }
        }
        return ans;
    }
};