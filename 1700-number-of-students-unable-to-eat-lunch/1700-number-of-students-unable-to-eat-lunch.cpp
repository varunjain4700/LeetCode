class Solution
{
    public:
        int countStudents(vector<int> &students, vector<int> &sandwiches)
        {
            int n = students.size();
            int zeroes = 0, ones = 0;
            for (int i = 0; i < n; i++)
            {
                if (students[i] == 0)
                    zeroes++;
                else
                    ones++;
            }
            for (int i = 0; i < n; i++)
            {
                if (sandwiches[i] == 0 && zeroes > 0)
                    zeroes--;
                else if (sandwiches[i] == 1 && ones > 0)
                    ones--;
                else
                    return n - i;
            }
            return 0;
        }
};