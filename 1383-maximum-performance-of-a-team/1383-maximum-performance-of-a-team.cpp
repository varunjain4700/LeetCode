class Solution
{
    public:
        static bool cmp(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first;
        }
    int maxPerformance(int n, vector<int> &speed, vector<int> &eff, int k)
    {
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back({ eff[i],
                speed[i] });
        }
        sort(nums.begin(), nums.end(), cmp);
        priority_queue<int, vector < int>, greater < int>> pq;
        long long total = 0, minm = INT_MAX, ans = 0;
        for (int i = 0; i < k; i++)
        {
            total += nums[i].second;
            ans = max(ans, total *nums[i].first);
            pq.push(nums[i].second);
        }
        for (int i = k; i < n; i++)
        {
            if (nums[i].second > pq.top())
            {
                total -= pq.top();
                pq.pop();
                total += nums[i].second;
                ans = max(ans, total *nums[i].first);
                pq.push(nums[i].second);
            }
        }
        return ans % 1000000007;
    }
};