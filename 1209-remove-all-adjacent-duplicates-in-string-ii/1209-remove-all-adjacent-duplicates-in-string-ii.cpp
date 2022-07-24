class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            int n = s.size();
            stack<pair<char, int>> st;
            int i = 0, cnt = 1;
            char ch = s[0];
            for (int i = 1; i < n; i++)
            {
                if (s[i] != s[i - 1])
                {
                    st.push({ ch,
                        cnt });
                    ch = s[i];
                    cnt = 0;
                }
                cnt++;
            }
            if (cnt > 0)
                st.push({ ch,
                    cnt });
            stack<pair<int, int>> temp;
            while (!st.empty())
            {
                pair<char, int> p1 = st.top();
                st.pop();
                int val;
                if (p1.second >= k)
                {
                    val = p1.second / k;
                    p1.second -= (val *k);
                }
                if (!temp.empty())
                {
                    pair<char, int> p2 = temp.top();
                   	//cout << p1.first << " " << p2.first << endl;
                    if (p2.first == p1.first)
                    {
                        temp.pop();
                        val = (p1.second + p2.second) / k;
                        p1.second += p2.second;
                        p1.second -= (val *k);
                    }
                }
                if (p1.second > 0)
                    temp.push(p1);
            }
            string res = "";
            while (!temp.empty())
            {
                char ch = temp.top().first;
                int cnt = temp.top().second;
                temp.pop();
                for (int i = 0; i < cnt; i++)
                    res += ch;
            }
            return res;
        }
};