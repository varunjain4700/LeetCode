class Solution
{
    public:
        bool validPalindrome(string s)
        {
            int n = s.size();
            bool flag = 1;
            for (int i = 0; i < n / 2; i++)
            {
                if (s[i] != s[n - i - 1])
                {
                    {
                        int j = i + 1, k = n - i - 1;
                        while (j < k)
                        {
                            if (s[j] != s[k])
                            {
                                flag = 0;
                                break;
                            }
                            j++;
                            k--;
                        }
                        if (j >= k)
                            flag = 1;
                        if (!flag)
                        {
                            j = i, k = n - i - 2;
                            while (j < k)
                            {
                                if (s[j] != s[k])
                                {
                                    flag = 0;
                                    break;
                                }
                                j++;
                                k--;
                            }
                            if (j >= k)
                                flag = 1;
                        }
                    }
                    break;
                }
            }
            if (flag)
                return true;
            return false;
        }
};