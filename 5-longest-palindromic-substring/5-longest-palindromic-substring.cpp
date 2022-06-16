class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int n = s.size(), ans = 1, start = 0, end = 0, l, r;
            for (int i = 0; i < n - 1; i++)
            {
                l = i, r = i + 1;	//even substrings
                while (l >= 0 && r < n && s[l] == s[r])
                {
                    if (r - l + 1 > ans)
                    {
                        ans = r - l + 1;
                        start = l;
                        end = r;
                    }
                    l--;
                    r++;
                }
                l = i, r = i + 2;	//odd substrings
                while (l >= 0 && r < n && s[l] == s[r])
                {
                    if (r - l + 1 > ans)
                    {
                        ans = r - l + 1;
                        start = l;
                        end = r;
                    }
                    l--;
                    r++;
                }
            }

            return s.substr(start, ans);
        }
};