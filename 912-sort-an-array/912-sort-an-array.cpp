class Solution
{
    public:
        vector<int> merge(vector<int> &left, vector<int> &right)
        {
            vector<int> res;
            int i = 0, j = 0;
            int n = left.size(), m = right.size();
            while (i < n && j < m)
            {
                if (left[i] < right[j])
                {
                    res.push_back(left[i]);
                    i++;
                }
                else
                {
                    res.push_back(right[j]);
                    j++;
                }
            }
            while (i < n)
            {
                res.push_back(left[i]);
                i++;
            }
            while (j < m)
            {
                res.push_back(right[j]);
                j++;
            }
            return res;
        }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return nums;
        vector<int> left,right;
        for (int i = 0; i < n / 2; i++)
            left.push_back(nums[i]);
        for (int i = n / 2; i < n; i++)
            right.push_back(nums[i]);
        vector<int> a = sortArray(left);
        vector<int> b = sortArray(right);
        return merge(a, b);
    }
};