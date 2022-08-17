class Solution
{
    public:
       	//can't jump backward twice in a row
        int minimumJumps(vector<int> &forbidden, int a, int b, int end)
        {
            set<int> pos;
            for (int i = 0; i < forbidden.size(); i++)
                pos.insert(forbidden[i]);
            queue<pair<int, int>> q;
            q.push({ 0,
                0 });
            vector<vector < int>> vis(10001, vector<int> (2, 0));
            vis[0][0] = 1;
           	//contains a pair in which first quantity denoted the current pos and second tells whether it reached this position by backward/ forward jump
            int lvl = 0;
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first, flag = p.second;
                    if (x == end)
                        return lvl;
                    if (x + a <= 10000 && !vis[x + a][0] && pos.find(x + a) == pos.end())
                    {
                        q.push({ x + a,
                            0 });
                        vis[x + a][0] = 1;
                    }
                    if (x - b >= 0 && flag != 1 && !vis[x - b][0] && pos.find(x - b) == pos.end())
                    {
                        q.push({ x - b,
                            1 });
                        vis[x - b][1] = 1;
                    }
                }
                lvl++;
            }
            return -1;
        }
};