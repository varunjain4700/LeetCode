class Solution
{
    public:

        string minRemoveToMakeValid(string s)
        {
            int n = s.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    st.push(i);
                else if (s[i] == ')')
                {
                    if (!st.empty())
                        st.pop();
                    else
                    {
                        s[i] = '?';
                    }
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (!st.empty() && st.top() == i)
                {
                    s[i] = '?';
                    st.pop();
                }
            }
            string res;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != '?')
                    res += s[i];
            }
            return res;
        }
};