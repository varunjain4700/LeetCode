class Solution
{
    public:
        vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
        {
            int n = words2.size();
            vector<int> max_freq(26, 0);
            for (int i = 0; i < n; i++)
            {
                vector<int> freq(26, 0);
                for (int j = 0; j < words2[i].size(); j++)
                {
                    freq[words2[i][j] - 'a']++;
                }
                for (int j = 0; j < 26; j++)
                {
                    max_freq[j] = max(max_freq[j], freq[j]);
                }
            }
            vector<string> res;
            for (int i = 0; i < words1.size(); i++)
            {
                vector<int> freq(26, 0);
                for (int j = 0; j < words1[i].size(); j++)
                {
                    freq[words1[i][j] - 'a']++;
                }
                bool flag = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (freq[j] <max_freq[j]){
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    res.push_back(words1[i]);
            }
            return res;
        }
};