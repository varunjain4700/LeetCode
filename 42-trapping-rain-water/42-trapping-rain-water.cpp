class Solution
{
    public:
       	//                1
       	// 1              1
       	// 1        1     1
       	// 1  1     1  1  1
       	// 1  1     1. 1  1
       	// 4. 2. 0. 3. 2. 5
        int trap(vector<int> &height)
        {
           	//O(1) space approach
            int l = 0, r = height.size() - 1;
            int left_max = 0, right_max = 0, ans = 0;
            while (l <= r)
            {
                if (height[l] <= height[r])
                {
                    if (height[l] >= left_max)
                        left_max = height[l];
                    else
                        ans += left_max - height[l];
                    l++;
                }
                else
                {
                    if (height[r] >= right_max)
                        right_max = height[r];
                    else
                        ans += right_max - height[r];
                    r--;
                }
            }
            return ans;

           	// O(n) space approach

           	// int n = height.size();
           	// vector<int> max_right(n, 0);
           	// max_right[n - 1] = height[n - 1];
           	// for (int i = n - 2; i >= 0; i--)
           	//     max_right[i] = max(max_right[i + 1], height[i]);
           	// int ans = 0, max_left = height[0];
           	// for (int i = 1; i < n - 1; i++)
           	// {
           	//     max_left = max(max_left, height[i]);
           	//     ans+= abs(height[i] - min(max_left, max_right[i]));
           	// }
           	// return ans;
        }
};