class Solution
{
    public:
        int maximumProduct(vector<int> &nums, int k)
        {
            int n = nums.size();
            priority_queue<int, vector < int>, greater < int>> pq;
            for (int i = 0; i < n; i++)
                pq.push(nums[i]);
            while (k > 0)
            {
                int temp = pq.top();
                pq.pop();
                pq.push(temp + 1);
                k--;
            }
            long long ans = 1, mod = 1e9 + 7;
            while (!pq.empty())
            {
                ans = (ans % mod *pq.top() % mod) % mod;
                pq.pop();
            }
            return ans;
        }
};