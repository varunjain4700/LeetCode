class Solution
{
    public:
        void solve(vector<string> &res, string str, int open, int close)
        {
            if (open == 0 && close == 0)
            {
                res.push_back(str);
                return;
            }
            if (close > open)
                solve(res, str + ")", open, close - 1);
            if (open > 0)
                solve(res, str + "(", open - 1, close);
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        solve(res, "", n, n);
        return res;
    }
};