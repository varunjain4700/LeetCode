class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 0)
                return 0;
            unordered_map<int, bool> mp;
            for (int i = 0; i < n; i++)
                mp[nums[i]] = 0;
            int ans = 1;
            for (int i = 0; i < n; i++)
            {
                if (mp[nums[i]] == 1)
                    continue;
                int curr = nums[i], temp = 1;
                mp[nums[i]] = 1;
                while (mp.find(++curr) != mp.end())
                {
                    mp[curr] = 1;
                    temp++;
                }
                curr = nums[i];
                while (mp.find(--curr) != mp.end())
                {
                    mp[curr] = 1;
                    temp++;
                }
                ans = max(ans, temp);
            }
            return ans;
        }
};