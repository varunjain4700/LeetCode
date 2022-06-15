class Solution
{
    public:
        void find_permutations(int idx, vector<int> &cookies, int n, vector<vector< int>> &res)
        {
            if (idx == n)
            {
                res.push_back(cookies);
                return;
            }
            for (int i = idx; i < n; i++)
            {
                swap(cookies[idx], cookies[i]);
                find_permutations(idx + 1, cookies, n, res);
                swap(cookies[idx], cookies[i]);
            }
        }
    bool solve(vector<int> &nums, int mid, int k)
    {
        int total = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid)
                return false;
            sum += nums[i];
            if (sum > mid)
            {
                total++;
                sum = nums[i];
            }
        }
        if (total <= k)
            return true;
        return false;
    }
    int binary_search(vector<int> &nums, int k)
    {
        int low = 1, high = 1e6;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (solve(nums, mid, k))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    int distributeCookies(vector<int> &cookies, int k)
    {
       	//first intution-find all the permutations of array and apply binary search on each permutation.Lets see it exceeds time limit or not.
        vector<vector < int>> res;
        find_permutations(0, cookies, cookies.size(), res);
        int ans = INT_MAX;
        for (int i = 0; i < res.size(); i++)
        {
            ans = min(ans, binary_search(res[i], k));
        }
        return ans;
    }
};