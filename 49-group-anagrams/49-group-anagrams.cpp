class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            int n = strs.size();
            vector<pair<string, string>> words;
            for (int i = 0; i < n; i++)
            {
                string temp = strs[i];
                sort(temp.begin(), temp.end());
                words.push_back({ temp,
                    strs[i] });
            }
            sort(words.begin(), words.end());
            vector<vector < string>> res;
            vector<string> group;
            for (int i = 0; i < n; i++)
            {
                if (i > 0 && words[i].first != words[i - 1].first)
                {
                    res.push_back(group);
                    group.clear();
                }
                group.push_back(words[i].second);
            }
            if (!group.empty())
                res.push_back(group);
            return res;
        }
};