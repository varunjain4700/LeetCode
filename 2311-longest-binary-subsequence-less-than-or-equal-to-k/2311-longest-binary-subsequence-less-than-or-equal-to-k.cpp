class Solution
{
    public:
        bool check(vector<int> &nums, int k)
        {
            int n = nums.size();
            long long ans = 0;
            int i = n - 1;
            while (i >= 0)
            {
                if (nums[i] == 1)
                {
                    if (n - i - 1 >= 30)	//to prevent overflow(as k can be 10^9 at max)
                        return false;
                    ans += pow(2, n - i - 1);
                }
                i--;
                if (ans > k)
                    return false;
            }
            return true;
        }
    int longestSubsequence(string s, int k)
    {
        int n = s.size();
        vector<int> temp;
        for (int i = n - 1; i >= 0; i--)
        {
            temp.push_back(s[i] - '0');
            if (s[i] == '1')
            {
                reverse(temp.begin(), temp.end());
                if (!check(temp, k))
                    temp.erase(temp.begin());
                reverse(temp.begin(), temp.end());
            }
        }
        return temp.size();
    }
};