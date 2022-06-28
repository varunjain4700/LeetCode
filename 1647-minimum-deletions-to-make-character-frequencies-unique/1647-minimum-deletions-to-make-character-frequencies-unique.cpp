class Solution
{
    public:
        int minDeletions(string s)
        {
            int n = s.size();
            vector<int> freq(26, 0);
            for (int i = 0; i < n; i++)
            {
                freq[s[i] - 'a']++;
            }
            priority_queue<int> pq;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] != 0)
                    pq.push(freq[i]);
            }
            int cnt = 0;
            int prev = pq.top();
            pq.pop();
            cnt += prev;
            while (!pq.empty())
            {
                if (pq.top() >= prev)
                {
                    cnt += prev - 1;
                    prev--;
                }
                else
                {
                    cnt += pq.top();
                    prev = pq.top();
                }
                pq.pop();
                if (prev <= 1)
                    break;
            }
            return n - cnt;
        }
};