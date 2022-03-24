class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &nums)
        {
            vector<int> res;
            int n = nums.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (!st.empty() && st.top() > 0 && nums[i] < 0)
                {
                    while (!st.empty() && st.top() < abs(nums[i]) && st.top() > 0)
                    {
                        st.pop();
                    }
                    if (!st.empty() && st.top() == abs(nums[i]))
                        st.pop();
                    else if (st.empty() || (!st.empty() && st.top() < 0) || (!st.empty() && st.top() > 0 && st.top() < abs(nums[i])))
                        st.push(nums[i]);
                }
                else
                    st.push(nums[i]);
            }
            while (!st.empty())
            {
                res.push_back(st.top());
                st.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
};