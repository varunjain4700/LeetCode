class Solution
{
    public:
        int countSubstrings(string s)
        {
            int n = s.size(), ans = 0;
            for (int i = 0; i < n; i++)
            {
               	//odd length substrings
                int start = i, end = i + 2;
                while (start >= 0 && end < n && s[start] == s[end])
                {
                    start--;
                    end++;
                    ans++;
                }
                ans++;	//increment the answer for single character strings

               	//even length substrings
                start = i;
                end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end])
                {
                    start--;
                    end++;
                    ans++;
                }
            }
            return ans;
        }
};