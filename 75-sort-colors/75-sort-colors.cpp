class Solution
{
    public:
       	//first approach is to sort the array by any sorting algorithm- time complexity will be O(nlogn).
       	//second approach is by counting the instances of 0's,1's and 2's - time complexity be O(n) but will need 2 passes atleast.
       	//Hence, the most optimal approach is by using just one pass.
        void sortColors(vector<int> &nums)
        {
            int n = nums.size();
            int start = 0, end = n - 1;
            int mid = 0;
            while (mid <= end)
            {
                if (nums[mid] == 0)
                {
                    swap(nums[mid], nums[start]);
                    mid++;
                    start++;
                }
                else if (nums[mid] == 1)
                    mid++;
                else
                {
                    swap(nums[mid], nums[end]);	//mid pointer will not move forward
                    end--;
                }
            }
        }
};