class Solution
{
    public:
        int subarraysDivByK(vector<int> &nums, int k)
        {
            int n = nums.size();
            map<int, int> mp;
            int curr_sum = 0, cnt = 0;
            mp[0] = 1;
            for (int i = 0; i < n; i++)
            {
                curr_sum = (curr_sum+nums[i])%k;
                int rem = (curr_sum +k)% k;
                cnt+=mp[rem];
                mp[rem]++;
            }
            return cnt;
        }
};