class Solution
{
    public:
       	//matching all the parentheses pair and popping them
       	//at last stack will be left with indexes which are a hurdle or not letting the string become longest valid, hence just need to check such adjacent indexes and we will get the desired answer
       	//one thing that needs to be remembered is that in this question is that we are also putting the closing bracket in the stack 
        int longestValidParentheses(string s)
        {
            int n = s.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    st.push(i);
                }
                else
                {
                    if (!st.empty())
                    {
                        if (s[st.top()] == '(')
                            st.pop();
                        else
                            st.push(i);
                    }
                    else
                        st.push(i);
                }
            }
            int ans = 0, i = n;
            while (!st.empty())
            {
                int j = st.top();
               	//cout<<i<<" "<<j<<endl;
                st.pop();
                ans = max(ans, i - j - 1);
                i = j;
            }
            ans = max(ans, i);
            return ans;
        }
};