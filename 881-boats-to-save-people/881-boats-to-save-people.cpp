class Solution
{
    public:
        int numRescueBoats(vector<int> &people, int limit)
        {
            int n = people.size();
            sort(people.begin(), people.end());
            int i = 0, j = n - 1, ans = 0;
            while (i <= j)
            {
                ++ans;
                if (i == j)
                    ++i;
                else if (people[i] + people[j] > limit)
                    --j;
                else
                {
                    ++i;
                    --j;
                }
            }
            return ans;
        }
};