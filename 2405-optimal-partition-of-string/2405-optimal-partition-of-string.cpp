class Solution
{
    public:
        int partitionString(string s)
        {
            int partitions = 1;
            vector<int> frequency(26, 0);
            for (int i = 0; i < s.size(); i++)
            {
                frequency[s[i] - 'a']++;
                if (frequency[s[i] - 'a'] > 1)
                {
                    partitions++;
                    frequency.assign(26, 0);
                    frequency[s[i] - 'a'] = 1;
                }
            }
            return partitions;
        }
};