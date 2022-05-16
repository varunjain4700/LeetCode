class Solution
{
    public:
        void setZeroes(vector<vector < int>> &mat)
        {
            int n = mat.size(), m = mat[0].size();
            int col_zero = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        if (j == 0)
                            col_zero = 0;
                        mat[i][0] = 0;
                        if (j != 0)
                            mat[0][j] = 0;
                    }
                }
            }
            for (int i = 1; i < n; i++)
            {
                if (mat[i][0] == 0)
                {
                    for (int j = 0; j < m; j++)
                        mat[i][j] = 0;
                }
            }
            for (int j = 1; j < m; j++)
            {
                if (mat[0][j] == 0)
                {
                    for (int i = 0; i < n; i++)
                        mat[i][j] = 0;
                }
            }
           	//  for (int i = 0; i < n; i++)
           	// {
           	//     for (int j = 0; j < m; j++)
           	//     {
           	//         cout<<mat[i][j]<<" ";
           	//     }
           	//      cout<<endl;
           	//  }
            if (mat[0][0] == 0)
            {
                for (int i = 0; i < m; i++)
                    mat[0][i] = 0;
            }
            if (col_zero == 0)
            {
                for (int i = 0; i < n; i++)
                    mat[i][0] = 0;
            }
        }
};