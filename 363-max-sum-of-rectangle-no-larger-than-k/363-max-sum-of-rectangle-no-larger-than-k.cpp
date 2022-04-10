class Solution
{
    public:
       	//similar to number of submatrices that sum to target
        int maxSumSubmatrix(vector<vector < int>> &mat, int val)
        {
            int n = mat.size(), m = mat[0].size();
            int ans = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                vector<int> row(m, 0);
                for (int j = i; j < n; j++)
                {
                    for (int k = 0; k < m; k++)
                    {
                        row[k] += mat[j][k];
                    }
                    vector<int> temp = row;
                    for (int k = 1; k < m; k++)
                        temp[k] += temp[k - 1];
                    set<int>s;
                    for (int k = 0; k < m; k++)
                    {
                        if(temp[k]<=val)
                            ans=max(ans,temp[k]);
                        auto it = s.lower_bound(temp[k] - val);
                        if (it !=s.end())
                        {
                           // cout<<temp[k]<<" "<<*it<<endl;
                            ans = max(ans, temp[k] - *it);
                        }
                         s.insert(temp[k]);
                    }
                }
            }
            return ans;
        }
};