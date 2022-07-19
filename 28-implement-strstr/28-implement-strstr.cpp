class Solution
{
    public:
        int brute_force(string &text, string &pattern)
        {
            int m = text.size(), n = pattern.size();
            for (int i = 0; i < m - n + 1; i++)
            {
                int j;
                for (j = 0; j < n; j++)
                {
                    if (text[i + j] != pattern[j])
                        break;
                }
                if (j == n)
                    return i;
            }
            return -1;
        }
    vector<int> find_lps(string pattern)
    {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int i = 0, j = 1;
        while (j < n)
        {
            if (pattern[i] == pattern[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    lps[j] = 0;
                    j++;
                }
                else
                {
                    i = lps[i - 1];
                }
            }
        }
        return lps;
    }
    int strStr(string text, string pattern)
    {
       	//return brute_force(text,pattern);

       	//Using KMP algorithm
        int m = text.size(), n = pattern.size();
        vector<int> lps = find_lps(pattern);
       	//lps-->longest proper prefix which is also a suffix.
       	//  for(int i=0;i < n;i++)
       	//     cout<<lps[i]<<" ";
       	// cout<<endl;
        int i = 0, j = 0;
        while (i < m)
        {
           	//cout<<i<<" "<<j<<endl;
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                {
                    j = lps[j - 1];
                }
            }
            if (j == n)
                return i - j;
        }
        return -1;
    }
};