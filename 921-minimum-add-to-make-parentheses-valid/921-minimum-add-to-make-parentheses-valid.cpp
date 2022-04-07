class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            int n = s.size();
            stack<int> st;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    st.push(i);
                else
                {
                    if (st.empty())
                        ans++;
                    else
                        st.pop();
                }
            }
            ans += st.size();
            return ans;
        }
};