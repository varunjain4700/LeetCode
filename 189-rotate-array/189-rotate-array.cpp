class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int n = nums.size();
            k = k % n;
            if (k == 0)
                return;
           	//Using extra space O(n)
           	map<int, int> mp;
           	for (int i = 0; i < n; i++)
           	    mp[i] = nums[i];
           	for (int i = 0; i < n; i++)
           	{
           	    nums[(i + k) % n] = mp[i];
           	}

           	//  Visualize like this to understand:

           	// nums = "----->-->"; k =3
           	// result = "-->----->";

           	// reverse "----->-->" we can get "<--<-----"
           	// reverse "<--" we can get "--><-----"
           	// reverse "<-----" we can get "-->----->"
            // reverse(nums.begin(), nums.end());
            // reverse(nums.begin(), nums.begin() + k);
            // reverse(nums.begin() + k, nums.end());
        }
};