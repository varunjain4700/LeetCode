class Solution
{
    public:
        string minWindow(string s, string t)
        {
            int n = s.size(), m = t.size();
            if (m > n)
                return "";
            map<char, int> mp;
            int cnt = 0;	//number of distinct letters
            for (int i = 0; i < m; i++)
            {
                if (mp.find(t[i]) == mp.end())
                    cnt++;
                mp[t[i]]++;
            }
            int i = 0, j = 0;
            int ans = n + 1, start, end;
            while (i < n)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    cnt--;
                while (cnt == 0)
                {
                    if (i - j + 1 < ans)
                    {
                        ans = i - j + 1;
                        start = j;
                        end = i;
                    }
                    mp[s[j]]++;
                    if (mp[s[j]] > 0)
                        cnt++;
                    j++;
                }
                i++;
            }
            if (ans == n + 1)
                return "";
            return s.substr(start, end - start + 1);
        }
};