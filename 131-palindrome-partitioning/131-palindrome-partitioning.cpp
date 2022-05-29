class Solution
{
    public:
        bool check(string s)
        {
            int n = s.size();
            for (int i = 0; i < n / 2; i++)
            {
                if (s[i] != s[n - i - 1])
                    return false;
            }
            return true;
        }
    void solve(int idx, string s, vector<string>&temp, vector<vector< string>> &res)
    {
        if (idx == s.size())
        {
            res.push_back(temp);
            return;
        }
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str = s.substr(idx, i - idx + 1);
            if (check(str))
            {
                temp.push_back(str);
                solve(i + 1, s, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector < string>> partition(string s)
    {
        vector<vector < string>> res;
        vector<string> temp;
        solve(0, s, temp, res);
        return res;
    }
};