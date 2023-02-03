class Solution
{
    public:
        bool isAlienSorted(vector<string> &words, string order)
        {
            vector<int> rank(26, 0);
            for (int i = 0; i < 26; i++)
                rank[order[i] - 'a'] = i;
            int num = words.size();
            for (int i = 1; i < num; i++)
            {
                int minm = min(words[i].size(), words[i - 1].size());
                int j;
                for (j = 0; j < minm; j++)
                {
                    if (rank[words[i - 1][j] - 'a'] > rank[words[i][j] - 'a'])
                        return false;
                    else if (rank[words[i - 1][j] - 'a'] < rank[words[i][j] - 'a'])
                        break;
                }
                if (j == minm)
                {
                    if (words[i - 1].size() > words[i].size())
                        return false;
                }
            }
            return true;
        }
};