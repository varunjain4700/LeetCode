class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size();
            vector<int> pre(n, 0), suff(n, 0);
            map<int, int> p, s;
            pre[0] = nums[0];
            p[pre[0]] = 1;
            for (int i = 1; i < n; i++)
            {
                pre[i] += pre[i - 1] + nums[i];
                if (p.find(pre[i]) == p.end())
                    p[pre[i]] = i + 1;
            }
            suff[n - 1] = nums[n - 1];
            s[suff[n - 1]] = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                suff[i] = suff[i + 1] + nums[i];
                if (s.find(suff[i]) == s.end())
                {
                    s[suff[i]] = n - i;
                }
            }
            int ops = INT_MAX, ans = 0, temp = x;
            for (int i = 0; i < n; i++)
            {
                ans = 0;
                x = temp;
                x -= pre[i];
                ans += i + 1;
                if (x == 0)
                    ops = min(ops, ans);
                if (s.find(x) != s.end())
                {
                    ans += s[x];
                   	//  cout<<i<<"-"<<ans<<endl;
                    if (ans <= n)
                        ops = min(ops, ans);
                }
            }
            //cout << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                ans = 0;
                x = temp;
                x -= suff[i];
                ans += n - i;
                if (x == 0)
                    ops = min(ops, ans);
                if (p.find(x) != p.end())
                {
                    ans += p[x];
                   	// cout<<i<<",,"<<ans<<endl;
                    if (ans <= n)
                        ops = min(ops, ans);
                }
            }
            if (ops == INT_MAX)
                return -1;
            return ops;
        }
};