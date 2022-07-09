class Solution
{
    public:
        int maxResult(vector<int> &nums, int k)
        {
            int n = nums.size();
            deque<int> dq;
            for (int i = 0; i < n; i++)
            {
                while (!dq.empty() && dq.front() < i - k)
                {
                    dq.pop_front();
                }
                int curr = nums[i];
                if (!dq.empty())
                    curr += nums[dq.front()];
                nums[i] = curr;
                while (!dq.empty() && nums[i] > nums[dq.back()])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
           	// for(int i=0;i < n;i++)
           	//     cout<<nums[i]<<" ";
           	// cout<<endl;
            return nums[n - 1];
        }
};