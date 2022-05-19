class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, bool> mp;
            for (int i = 0; i < n; i++)
                mp[nums[i]] = 0;
            int i = 0, ans = 0, len = 0, curr;
            while (i < n)
            {
                len = 0;
                curr = nums[i];
                int temp = curr - 1;
                while (mp.find(curr) != mp.end() && mp[curr] == 0)
                {
                    mp[curr] = 1;
                    len++;
                    curr++;
                }
                while (mp.find(temp) != mp.end() && mp[temp] == 0)
                {
                    mp[temp] = 1;
                    len++;
                    temp--;
                }
                ans = max(ans, len);
                i++;
            }
            return ans;
        }
};