class Solution
{
    public:
        double myPow(double x, int n)
        {
            double ans = 1;
            long long power = n;
            bool f = 0;
            if (power < 0)
            {
                power *= -1;
                f = 1;
            }
            while (power > 0)
            {
                if (power % 2 == 1)
                {
                    if (f)
                        ans /= x;
                    else
                        ans *= x;
                    power--;
                }
                else
                {
                    x *= x;
                    power /= 2;
                }
            }
            return ans;
        }
};