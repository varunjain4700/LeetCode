class Solution
{
    public:
       	//finding the score of inner pair of parentheses and pushing it towards parents 
        int scoreOfParentheses(string s)
        {
            int n = s.size();
            stack<int> st;
            st.push(0);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    st.push(0);
                else
                {
                    int curr = st.top();
                    st.pop();
                    st.top() += max(curr *2, 1);
                }
            }
            return st.top();
        }
};