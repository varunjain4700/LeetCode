class Solution
{
    public:
       	//expanding from the centre and moving towards both the ends while checking if the characters match or not
        string longestPalindrome(string s)
        {
            int n = s.size(), low = 0, high = 0, idx = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                low = high = i;	//checking for odd length substrings
                while (low >= 0 && high < n)
                {
                    if (s[low] == s[high])
                    {
                        if (high - low + 1 > ans)
                        {
                            ans = high - low + 1;
                            idx = low;
                        }
                        low--;
                        high++;
                    }
                    else
                        break;
                }
                low = i, high = i + 1;	//checking for even length substrings
                while (low >= 0 && high < n)
                {
                    if (s[low] == s[high])
                    {
                        if (high - low + 1 > ans)
                        {
                            ans = high - low + 1;
                            idx = low;
                        }
                        low--;
                        high++;
                    }
                    else
                        break;
                }
            }
           	//cout << idx << " " << ans << endl;
            return s.substr(idx, ans);
        }
};