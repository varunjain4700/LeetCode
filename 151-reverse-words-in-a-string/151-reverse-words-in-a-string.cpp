class Solution
{
    public:
        string reverseWords(string s)
        {
            reverse(s.begin(), s.end());
            int n = s.size();
            int i = 0;
            string ans = "", temp = "";
            bool flag = 0;
            while (i < n)
            {
                while (s[i] == ' ')
                {
                    if (flag)
                    {
                        reverse(temp.begin(), temp.end());
                        ans += temp + " ";
                        flag = 0;
                        temp.clear();
                    }
                    i++;
                }
                if (i < n && s[i] != ' ')
                {
                    temp += s[i];
                    flag = 1;
                    i++;
                }
            }
            if (!temp.empty())
            {
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
            }
            ans.pop_back();
            return ans;
        }
};