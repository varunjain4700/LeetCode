class Solution
{
    public:
        bool check(vector<int> &a, vector<int> &b)
        {
            for (int i = 0; i < 26; i++)
            {
                if (a[i] != b[i])
                    return false;
            }
            return true;
        }
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (m > n)
            return {};
        vector<int> freq1(26, 0), freq2(26, 0), ans;
        for (int i = 0; i < m; i++)
            freq2[p[i] - 'a']++;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            freq1[s[i] - 'a']++;
            if (i - j + 1 == m)
            {
                if (check(freq1, freq2))
                    ans.push_back(j);
                freq1[s[j] - 'a']--;
                j++;
            }
        }
        return ans;
    }
};