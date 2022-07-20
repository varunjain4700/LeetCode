class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            int n = s.size(), m = words.size();
            int cnt = 0;
            vector<vector < int>> adj(26);
            for (int i = 0; i < n; i++)
            {
                adj[s[i] - 'a'].push_back(i);
            }
            for (int i = 0; i < m; i++)
            {
                string str = words[i];
                int pos = 0;
                int j;
                for (j = 0; j < str.size(); j++)
                {
                    int charr = str[j] - 'a';
                    auto it = lower_bound(adj[charr].begin(), adj[charr].end(), pos);
                    if (it == adj[charr].end())
                        break;
                    else
                        pos = *it + 1;
                }
                if (j == str.size())
                    cnt++;
            }
            return cnt;
        }
};