class Solution
{
    public:
        bool isIsomorphic(string s, string t)
        {
            int n = s.size();
            map<char, char> mp, vis;
            for (int i = 0; i < n; i++)
            {
                if (!vis[t[i]] && mp.find(s[i]) == mp.end())
                {
                    mp[s[i]] = t[i];
                    vis[t[i]] = 1;
                }
                else
                {
                    if (mp[s[i]] != t[i])
                        return false;
                }
            }
              return true;
        }
};