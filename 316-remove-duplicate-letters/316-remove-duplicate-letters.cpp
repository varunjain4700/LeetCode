class Solution
{
    public:
        string removeDuplicateLetters(string s)
        {
            int n = s.size();
            vector<int> vis(26, 0);
            unordered_map<int, int> cnt;
            for (int i = 0; i < n; i++)
                cnt[s[i] - 'a']++;
            stack<char> st;
            for (int i = 0; i < n; i++)
            {
                cnt[s[i] - 'a']--;
                if (vis[s[i] - 'a'])
                    continue;
                while (!st.empty() && st.top() > s[i] && cnt[st.top() - 'a'] > 0)
                {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i] - 'a'] = 1;
            }
            string res;
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
};