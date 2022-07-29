class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string> &words, string pattern)
        {
            int n = words.size();
            vector<string> res;
            for (int i = 0; i < n; i++)
            {
                string str = words[i];
                unordered_map<char, char> mapping;	//mapping each character in pattern to a current character of the word.if the mapping already exists, then it should match with it otherwise its not a possible permuatation
                vector<int> vis(26, 0);//if the particular char has already been mapped,then we can't map it again
                int j;
                for (j = 0; j < str.size(); j++)
                {
                    if (!vis[str[j] - 'a'] && mapping.find(pattern[j]) == mapping.end())
                    {
                        mapping[pattern[j]] = str[j];
                        vis[str[j] - 'a'] = 1;
                    }
                    else
                    {
                        if (mapping[pattern[j]] != str[j])
                            break;
                    }
                }
                if (j == str.size())
                    res.push_back(str);
            }
            return res;
        }
};