class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            int n = s.size();
            vector<int> end(26, 0);
            for (int i = 0; i < n; i++)
            {
                end[s[i] - 'a'] = i;
            }
            vector<int> res;
            int len = 0, maxm = -1;
            for (int i = 0; i < n; i++)
            {
                maxm = max(maxm, end[s[i] - 'a']);
                len++;
                if (maxm == i)
                {
                    res.push_back(len);
                    maxm = -1;
                    len = 0;
                }
            }
            return res;
        }
};