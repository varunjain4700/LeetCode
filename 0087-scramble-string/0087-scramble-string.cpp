class Solution
{
    public:

        bool solve(string s1, string s2, unordered_map<string, bool> &mp)
        {
            int n = s1.size();
            if (s1 == s2)
                return true;
            if (n <= 1)
                return false;
            string key = s1 + s2;
            if (mp.find(key) != mp.end())
                return mp[key];
            for (int i = 1; i < n; i++)
            {

                bool temp1 = solve(s1.substr(0, i), s2.substr(n - i), mp) && solve(s1.substr(i), s2.substr(0, n - i), mp);	//Case-1:when substrings are swapped 
                bool temp2 = solve(s1.substr(0, i), s2.substr(0, i), mp) && solve(s1.substr(i), s2.substr(i), mp);	//Case-2:when substrings are not swapped
                if (temp1 || temp2)	//any of the case gives us true
                    return true;
            }
            return mp[key] = false;
        }
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};