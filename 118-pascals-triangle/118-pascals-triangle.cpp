class Solution
{
    public:
        vector<vector < int>> generate(int rows)
        {
            vector<vector < int>> res;
            res.push_back({ 1 });
            for (int i = 1; i < rows; i++)
            {
                vector<int> next_row = { 1 };
                for (int j = 1; j < res[i - 1].size(); j++)
                {
                    next_row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                next_row.push_back(1);
                res.push_back(next_row);
            }
            return res;
        }
};