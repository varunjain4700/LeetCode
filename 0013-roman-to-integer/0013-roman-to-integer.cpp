class Solution
{
    public:
        int romanToInt(string s)
        {
            unordered_map<char, int> mp;
            mp['I'] = 1;
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
            int n = s.size(), res = 0;
            for (int i = 0; i < n; i++)
            {
                if (i + 1 < n)
                {
                    string str;
                    str += s[i];
                    str += s[i + 1];
                    if (str == "IV")
                    {
                        res += 4;
                        i++;
                    }
                    else if (str == "IX")
                    {
                        res += 9;
                        i++;
                    }
                    else if (str == "XL")
                    {
                        res += 40;
                        i++;
                    }
                    else if (str == "XC")
                    {
                        res += 90;
                        i++;
                    }
                    else if (str == "CD")
                    {
                        res += 400;
                        i++;
                    }
                    else if (str == "CM")
                    {
                        res += 900;
                        i++;
                    }
                    else
                        res += mp[s[i]];
                }
                else
                    res += mp[s[i]];
               	//cout<<res<<endl;
            }
            return res;
        }
};