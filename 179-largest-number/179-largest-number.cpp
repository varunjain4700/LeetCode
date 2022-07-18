class Solution
{
    public:
        static bool cmp(int &a, int &b)
        {
            string s = to_string(a);
            string t = to_string(b);
            if (s + t > t + s)
                return true;
            return false;
        }
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += to_string(nums[i]);
        }
        int i = 0;
        while (ans[i] == '0')
            i++;
        string res = ans.substr(i);
        if (res == "")
            return "0";
        return res;
    }
};