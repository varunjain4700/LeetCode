class Solution
{
    public:
        vector<int> arrayChange(vector<int> &nums, vector<vector< int>> &ops)
        {
            vector<int> pos(1e6 + 5, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                pos[nums[i]] = i;
            }
            for (int i = 0; i < ops.size(); i++)
            {
                nums[pos[ops[i][0]]] = ops[i][1];
                pos[ops[i][1]] = pos[ops[i][0]];
            }
            return nums;
        }
};