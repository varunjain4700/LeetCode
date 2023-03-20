class Solution
{
    public:
        bool canPlaceFlowers(vector<int> &flowerbed, int n)
        {
            vector<int> nums = flowerbed;
            int sz = nums.size();
            for (int i = 0; i < sz; i++)
            {
                if (n == 0)
                    break;
                if (nums[i] == 0)
                {
                    int left = (i - 1 >= 0) ? nums[i - 1] : 0;
                    int right = (i + 1 < sz) ? nums[i + 1] : 0;
                    if (!left && !right)
                    {
                        nums[i] = 1;
                        n--;
                    }
                }
            }
            if (!n)
                return true;
            return false;
        }
};