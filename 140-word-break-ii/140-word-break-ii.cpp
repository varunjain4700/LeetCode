class Solution
{
    public:
        void solve(int idx, string s, string temp, unordered_set<string> &words, vector<string> &res)
        {
            if (idx == s.size())
            {
                temp.pop_back();
                res.push_back(temp);
                return;
            }
            string str = "";
            for (int i = idx; i < s.size(); i++)
            {
                str.push_back(s[i]);
                if (words.find(str) != words.end())
                {
                    solve(i + 1, s, temp + str + " ", words, res);
                }
            }
        }
    vector<string> wordBreak(string s, vector<string> &dict)
    {
        unordered_set<string> words;
        for (int i = 0; i < dict.size(); i++)
            words.insert(dict[i]);
        vector<string> res;
        solve(0, s, "", words, res);
        return res;
    }
};