class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, bool> mp;
            for (int i = 0; i < n; i++)
                mp[nums[i]] = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = nums[i], len = 1;
                while (mp.find(temp + 1) != mp.end() && mp[temp + 1] == 0)
                {
                    len++;
                    mp[temp + 1] = 1;
                    temp++;
                }
                temp = nums[i];
                while (mp.find(temp - 1) != mp.end() && mp[temp - 1] == 0)
                {
                    len++;
                    mp[temp - 1] = 1;
                    temp--;
                }
                ans = max(ans, len);
            }
            return ans;
        }
};