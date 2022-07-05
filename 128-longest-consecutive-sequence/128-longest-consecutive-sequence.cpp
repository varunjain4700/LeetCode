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
                int cnt = 1, element = nums[i] - 1;
                while (mp.find(element) != mp.end() && mp[element] == 0)
                {
                    mp[element] = 1;
                    element--;
                    cnt++;
                }
                element = nums[i] + 1;
                while (mp.find(element) != mp.end() && mp[element] == 0)
                {
                    mp[element] = 1;
                    element++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
            return ans;
        }
};