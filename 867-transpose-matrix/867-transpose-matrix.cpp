class Solution
{
    public:
        vector<vector < int>> transpose(vector<vector < int>> &mat)
        {
            vector<vector < int>> res;
            for (int i = 0; i < mat[0].size(); i++)
            {
                vector<int> temp;
                for (int j = 0; j < mat.size(); j++)
                    temp.push_back(mat[j][i]);
                res.push_back(temp);
            }
            return res;
        }
};