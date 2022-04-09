class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            int n = nums.size();
            unordered_map<int, int> freq;
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            for (int i = 0; i < n; i++)
            {
                freq[nums[i]]++;
            }
            for (auto it: freq)
            {
                pq.push({ it.second,
                    it.first });
                if (pq.size() > k)
                    pq.pop();
            }
            vector<int> res;
            while (!pq.empty())
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
            return res;
        }
};