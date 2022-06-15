class Solution
{
    public:
        bool strongPasswordCheckerII(string s)
        {
            int n = s.size();
            if (n < 8)
                return false;
            bool small = false, capital = false, digit = false, special = false;
            for (int i = 0; i < n; i++)
            {
                if (i > 0 && s[i] == s[i - 1])
                    return false;
                if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
                    small = true;
                if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25)
                    capital = true;
                if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
                    digit = true;
                if (s[i] == '!' || s[i] == '@' || s[i] == '$' || s[i] == '^' || s[i] == '%' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')' || s[i] == '-' || s[i] == '+' || s[i] == '#')
                    special = true;
            }
            if (small && capital && digit && special)
                return true;
            return false;
        }
};