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
                if (pq.size() == k)
                {
                    if (freq[it.first] > pq.top().first)
                    {
                        pq.pop();
                        pq.push({ it.second,
                            it.first });
                    }
                }
                else
                    pq.push({ it.second,
                        it.first });
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