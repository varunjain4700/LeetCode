class Solution
{
    public:
       	//calculate number of subarrays such that sum=target
        int solve(vector<int> &nums, int target)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            mp[0] = 1;
            int curr_sum = 0, cnt = 0;
            for (int i = 0; i < n; i++)
            {
                curr_sum += nums[i];
                if (mp.find(curr_sum - target) != mp.end())
                    cnt += mp[curr_sum - target];
                mp[curr_sum]++;
            }
            return cnt;
        }
    int numSubmatrixSumTarget(vector<vector < int>> &mat, int target)
    {
       	//taking one row at a time and adding rest of the rows to it one by one(thus transforming a submatrix into a 1D array) and then finding number of subarrays such that sum=target
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = i; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    temp[k] += mat[j][k];
                }
                ans += solve(temp, target);
            }
        }
        return ans;
    }
};