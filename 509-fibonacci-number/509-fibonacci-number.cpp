class Solution
{
    public:
        int fib(int n)
        {
            if (n == 0 || n == 1)
                return n;
            int prev1 = 1, prev2 = 0, sum;
            for (int i = 0; i < n - 1; i++)
            {
                sum = prev1 + prev2;
                prev2 = prev1;
                prev1 = sum;
            }
            return sum;
        }
};