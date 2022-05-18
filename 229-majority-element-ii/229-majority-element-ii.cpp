class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            int n = nums.size();
            int ele1 = 2e9, cnt1 = 0, ele2 = 2e9, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == ele1)
                    cnt1++;
                else if (nums[i] == ele2)
                    cnt2++;
                else if (cnt1 == 0)
                {
                    cnt1 = 1;
                    ele1 = nums[i];
                }
                else if (cnt2 == 0)
                {
                    cnt2 = 1;
                    ele2 = nums[i];
                }
                else
                {
                    cnt1--;
                    cnt2--;
                }
            }
            vector<int> ans;
            cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == ele1)
                    cnt1++;
                else if (nums[i] == ele2)
                    cnt2++;
            }
            if (cnt1 > n / 3)
                ans.push_back(ele1);
            if (cnt2 > n / 3)
                ans.push_back(ele2);
            return ans;
        }
};