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
            int n = height.size();
            vector<int> max_right(n, 0);
            max_right[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--)
                max_right[i] = max(max_right[i + 1], height[i]);
            int ans = 0, max_left = height[0];
            for (int i = 1; i < n - 1; i++)
            {
                max_left = max(max_left, height[i]);
                ans+= abs(height[i] - min(max_left, max_right[i]));
            }
            return ans;
        }
};