class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            vector<int> cnt1(26, 0);
            int len1 = p.size(), len2 = s.size();
            for (int i = 0; i < len1; i++)
                cnt1[p[i] - 'a']++;
            vector<int> cnt2(26, 0), res;
            int i = 0, k = 0;
            while (i < len2)
            {
                cnt2[s[i] - 'a']++;
                if (i >= len1 - 1)
                {
                    bool flag = 0;
                    for (int j = 0; j < 26; j++)
                    {
                        if (cnt1[j] != cnt2[j])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                        res.push_back(k);
                    cnt2[s[k] - 'a']--;
                    k++;
                }
                i++;
            }
            return res;
        }
};