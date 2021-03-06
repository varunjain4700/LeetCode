class Solution
{
    public:
        int solve(int start, int target, int steps)
        {
            //cout<<start<<" "<<steps<<endl;
            if (target>=start)
                return steps+target-start;
            if (start % 2 == 0)
                return solve(start / 2, target, steps + 1);
            else
                return solve(start + 1, target, steps + 1);
        }
    int brokenCalc(int start, int target)
    {
        return solve(target, start, 0);
    }
};