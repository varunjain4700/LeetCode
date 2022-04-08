class Solution
{
    public:
       	//pre[0...i] denotes the prefix sum till index i
       	// x--->sum of subarray that needs to be deleted 
       	//(total_sum-x)%p=0 
       	//pre[n]%p-(pre[0...i]-pre[0...j])%p=0
       	//pre[0...j]%p=pre[n]%p-pre[0...i]%p
       	//adding p as it may be possible that rhs may become negative
       	//pre[0..j]%p=(pre[n]%p-pre[0..i]%p+p)%p
        int minSubarray(vector<int> &nums, int k)
        {
            long long n = nums.size(), total = 0;
            for (int i = 0; i < n; i++)
            {
                total += nums[i];
            }
            int target = total % k;
            if (target == 0)
                return 0;
            long long sum = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            int ans = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                sum = (sum + nums[i]) % k;
                if (mp.find((sum - target + k) % k) != mp.end())
                    ans = min(ans, i - mp[(sum - target + k) % k]);
                mp[sum % k] = i;
            }
            if (ans == INT_MAX || ans == n)
                return -1;
            return ans;
        }
};