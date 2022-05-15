class Solution
{
    public:
        void solve(int idx, string digits, string temp, vector<string> &res, vector<vector< int>> mp)
        {
            if (idx == digits.size())
            {
                res.push_back(temp);
                return;
            }
            for (int i = 0; i < mp[digits[idx] - '0' - 2].size(); i++)
            {
                temp[idx] = (mp[digits[idx] - '0' - 2][i] + 'a');
                solve(idx + 1, digits, temp, res, mp);
            }
        }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        string temp = digits;
        vector<string> res;
        vector<vector < int>> mp({
		{ 0,
                1,
                2 },
            { 3,
                4,
                5 },
            { 6,
                7,
                8 },
            { 9,
                10,
                11 },
            { 12,
                13,
                14 },
            { 15,
                16,
                17,
                18 },
            { 19,
                20,
                21 },
            { 22,
                23,
                24,
                25 } });
        solve(0, digits, temp, res, mp);
        return res;
    }
};