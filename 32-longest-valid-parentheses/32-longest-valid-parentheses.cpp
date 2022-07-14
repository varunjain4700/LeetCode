class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int n = s.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    st.push(i);
                else
                {
                    if (st.empty())
                        st.push(i);
                    else
                    {
                        if (s[st.top()] == '(')
                            st.pop();
                        else
                            st.push(i);
                    }
                }
            }
            int ans = 0, i = n, j = 0;
            while (!st.empty())
            {
                j = st.top();
                st.pop();
                ans = max(ans, i - j - 1);
                i = j;
            }
            ans = max(ans, i);
            return ans;
        }
};