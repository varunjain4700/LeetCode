class Solution
{
    public:
        int ladderLength(string start, string end, vector<string> &words)
        {
            unordered_set<string> dict;
            for (int i = 0; i < words.size(); i++)
            {
                dict.insert(words[i]);
            }
            if (dict.find(end) == dict.end())
                return 0;
            queue<string> q;
            q.push(start);
            dict.erase(start);
            int n = start.size(), steps = 1;
            while (!q.empty())
            {
                steps++;
                int sz = q.size();
                while (sz--)
                {
                    string curr_word = q.front();
                    q.pop();
                    for (int i = 0; i < n; i++)
                    {
                        char temp = curr_word[i];
                        for (char j = 'a'; j <= 'z'; j++)
                        {
                            curr_word[i] = j;
                            if (curr_word == end)
                                return steps;
                            if (dict.find(curr_word) != dict.end())
                            {
                                q.push(curr_word);
                                dict.erase(curr_word);
                            }
                        }
                        curr_word[i] = temp;
                    }
                }
            }
            return 0;
        }
};