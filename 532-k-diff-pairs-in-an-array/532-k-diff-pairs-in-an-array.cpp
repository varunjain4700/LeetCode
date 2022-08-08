class Solution
{
    public:
        int findPairs(vector<int> &nums, int k)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++)
                mp[nums[i]]++;
            int ans = 0;
            for (auto it: mp)
            {
                int num = it.first;
                if (k == 0)
                {
                    if (mp[num - k] > 1)
                        ans += 2;
                    continue;
                }
                if (mp.find(num - k) != mp.end())
                    ans++;
                if (mp.find(num + k) != mp.end())
                    ans++;
            }
            return ans / 2;
        }
};