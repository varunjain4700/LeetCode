class Solution
{
    public:
        vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r)
        {
            vector<bool> res;
            for (int i = 0; i < l.size(); i++)
            {
                vector<int> temp;
                for (int j = l[i]; j <= r[i]; j++)
                {
                    temp.push_back(nums[j]);
                }
                sort(temp.begin(), temp.end());
                int j, d = temp[1] - temp[0];
                for (j = 2; j < temp.size(); j++)
                {
                    if (temp[j] - temp[j - 1] != d)
                        break;
                }
                if (j == temp.size() || temp.size() == 2)
                    res.push_back(true);
                else
                    res.push_back(false);
            }
            return res;
        }
};