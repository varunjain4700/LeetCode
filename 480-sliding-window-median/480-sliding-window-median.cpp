class Solution
{
    public:
        vector<double> medianSlidingWindow(vector<int> &nums, int k)
        {
            int n = nums.size();
            multiset<int> minm;
            multiset<int, greater < int>> maxm;
            vector<double> res;
            double ans = 0;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (maxm.empty())
                    maxm.insert(nums[i]);
                else
                {
                    if (maxm.size() > minm.size())
                    {
                        if (nums[i]<*maxm.begin())
                        {
                            minm.insert(*maxm.begin());
                            maxm.erase(maxm.begin());
                            maxm.insert(nums[i]);
                        }
                        else
                            minm.insert(nums[i]);
                    }
                    else
                    {
                        if (nums[i] > *minm.begin())
                        {
                            maxm.insert(*minm.begin());
                            minm.erase(minm.begin());
                            minm.insert(nums[i]);
                        }
                        else
                            maxm.insert(nums[i]);
                    }
                }
                if (i >= k - 1)
                {
                    if (minm.size() == maxm.size())
                        ans = ((long long) *minm.begin() + (long long) *maxm.begin()) / (double) 2;
                    else
                        ans = *maxm.begin();
                    res.push_back(ans);
                    if (maxm.find(nums[j]) != maxm.end())
                        maxm.erase(maxm.find(nums[j]));
                    else
                        minm.erase(minm.find(nums[j]));
                    j++;
                }
            }
            return res;
        }
};