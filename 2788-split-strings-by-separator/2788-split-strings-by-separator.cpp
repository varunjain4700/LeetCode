class Solution
{
    public:
        vector<string> splitWordsBySeparator(vector<string> &words, char sep)
        {
            int n = words.size();
            vector<string> wordList;
            for (int i = 0; i < n; i++)
            {
                string str = "";
                for (int j = 0; j < words[i].size(); j++)
                {
                    if (words[i][j] == sep)
                    {
                        if (str != "")
                            wordList.push_back(str);
                        str = "";
                        continue;
                    }
                    str += words[i][j];
                }
                if (str != "")
                    wordList.push_back(str);
            }
            return wordList;
        }
};