class Solution
{
    public:
        bool matchReplacement(string s, string sub, vector<vector < char>> &mappings)
        {
            int n = s.size(), m = sub.size();
            unordered_map<char, unordered_set < char>> mp;
            for (int i = 0; i < mappings.size(); i++)
            {
                mp[mappings[i][0]].insert(mappings[i][1]);
            }
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (i - j + 1 == m)
                {
                    int k, l = i - m + 1;
                    for (k = 0; k < m; k++)
                    {
                        if (sub[k] == s[l])
                        {
                            l++;
                            continue;
                        }
                        else
                        {
                            if (mp[sub[k]].find(s[l]) == mp[sub[k]].end())
                                break;
                        }
                        l++;
                    }
                    if (k == m)
                        return true;
                    j++;
                }
            }
            return false;
        }
};