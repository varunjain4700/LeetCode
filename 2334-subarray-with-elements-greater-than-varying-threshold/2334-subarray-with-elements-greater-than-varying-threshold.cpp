class Solution
{
    public:
        int validSubarraySize(vector<int> &nums, int threshold)
        {
            stack<int> st;
            vector<int> nsl, nsr;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (st.empty())
                    nsl.push_back(-1);
                else if (nums[st.top()] < nums[i])
                    nsl.push_back(st.top());
                else
                {
                    while (!st.empty() && nums[st.top()] >= nums[i])
                        st.pop();
                    if (st.empty())
                        nsl.push_back(-1);
                    else
                        nsl.push_back(st.top());
                }
                st.push(i);
            }
            while (!st.empty())
                st.pop();
            for (int i = n - 1; i >= 0; i--)
            {
                if (st.empty())
                    nsr.push_back(n);
                else if (nums[st.top()] < nums[i])
                    nsr.push_back(st.top());
                else
                {
                    while (!st.empty() && nums[st.top()] >= nums[i])
                        st.pop();
                    if (st.empty())
                        nsr.push_back(n);
                    else
                        nsr.push_back(st.top());
                }
                st.push(i);
            }
            reverse(nsr.begin(), nsr.end());
            for (int i = 0; i < n; i++)
            {
               	//cout<<nsl[i]<<" "<<nsr[i]<<endl;
                int len = nsr[i] - nsl[i] - 1;
                if (nums[i] > threshold / len)
                    return len;
            }
            return -1;
        }
};