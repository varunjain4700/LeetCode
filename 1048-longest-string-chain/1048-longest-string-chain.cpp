class Solution
{
    public:
        static bool cmp(string a, string b)
        {
            if (a.size() < b.size())
                return true;
            return false;
        }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        map<string, vector < string>> adj;
        map<string, int> indegree;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (words[j].size() == words[i].size() + 1)
                {
                    int cnt = 0, l = 0;
                    for (int k = 0; k < words[j].size(); k++)
                    {
                        if (words[i][l] == words[j][k])
                        {
                            cnt++;
                            l++;
                        }
                    }
                    if (cnt == words[i].size())
                    {
                        adj[words[i]].push_back(words[j]);
                       	//cout<<words[i]<<" "<<words[j]<<endl;
                        indegree[words[j]]++;
                    }
                }
            }
        }
        queue<string> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[words[i]] == 0)
                q.push(words[i]);
        }
        int chain_len = 0;
        while (!q.empty())
        {
            int sz = q.size();
            chain_len++;
            while (sz--)
            {
                string str = q.front();
                q.pop();
                for (auto it: adj[str])
                {
                    indegree[it]--;
                    if (indegree[it] == 0)
                        q.push(it);
                }
            }
        }
        return chain_len;
    }
};