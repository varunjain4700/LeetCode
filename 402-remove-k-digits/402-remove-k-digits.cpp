class Solution
{
    public:
        string removeKdigits(string num, int k)
        {
            int n = num.size();
            stack<char> st;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && num[i] < st.top() && cnt < k)
                {
                    st.pop();
                    cnt++;
                }
                st.push(num[i]);
            }
            while (cnt != k)
            {
                st.pop();
                cnt++;
            }
            string ans;
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
           	//check for leading zeroes
            int i = 0;
            while (ans[i] == '0')
                i++;
            string res= ans.substr(i, n - i);
            if(res.empty())
                return "0";
            return res;
        }
};