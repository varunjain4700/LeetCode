class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            string s1, s2;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '#')
                {
                    if (!s1.empty())
                        s1.pop_back();
                }
                else
                    s1 += s[i];
            }
            for (int i = 0; i < t.size(); i++)
            {
                if (t[i] == '#')
                {
                    if (!s2.empty())
                        s2.pop_back();
                }
                else
                    s2 += t[i];
            }
            if (s1 == s2)
                return true;
            return false;
        }
};