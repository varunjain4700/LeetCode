class Solution
{
    public:
        bool strongPasswordCheckerII(string s)
        {
            int n = s.size();
            if (n < 8)
                return false;
            bool small, capital, digit, special;
            small = capital = digit = special = false;
            string str = "!@#$%^&*()-+";
            set<char> special_chars;
            for (int i = 0; i < str.size(); i++)
            {
                special_chars.insert(str[i]);
            }
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
                if (special_chars.find(s[i]) != special_chars.end())
                    special = true;
            }
            if (small && capital && digit && special)
                return true;
            return false;
        }
};