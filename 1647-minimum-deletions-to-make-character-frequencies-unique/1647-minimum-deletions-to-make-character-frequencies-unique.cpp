class Solution
{
    public:
        int minDeletions(string s)
        {
            int n = s.size();
            vector<int> freq(26, 0);
            for (int i = 0; i < n; i++)
                freq[s[i] - 'a']++;
            sort(freq.begin(), freq.end(), greater<int> ());
            int ans = 0;
            int cnt = freq[0];
            for (int i = 1; i < 26; i++)
            {
                if (freq[i] == 0)
                    break;
                if (cnt == 0)
                    ans += freq[i];
                else if (freq[i] < cnt)
                {
                    cnt = freq[i];
                }
                else
                {
                    cnt--;
                    ans += (freq[i] - cnt);
                }
            }
            return ans;
        }
};