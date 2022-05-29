class Solution
{
    public:

        bool check(char s)
        {
            for (int i = 0; i <= 9; i++)
            {
                if (s - '0' == i)
                    return true;
            }
            return false;
        }
    long double cal(vector<int> &d)
    {
        long double ans = 0;
        reverse(d.begin(), d.end());
        for (int i = 0; i < d.size(); i++)
        {
            ans += d[i] *pow(10, i);
        }
        return ans;
    }
    string discountPrices(string s, int disc)
    {
        int n = s.size();
        int i = 0;
        string res = "";
        while (i < n)
        {
            res += s[i];
            bool flag = 0;
            int j = i;
            if ((i > 0 && s[i] == '$' && s[i - 1] == ' ') || (i == 0 && s[i] == '$'))
            {
                i++;
                if (s[i] == ' ')
                {
                    continue;
                }
                vector<int> d;
                while (i < n && s[i] != ' ')
                {
                    if (!check(s[i]))
                    {
                        flag = 1;
                        break;
                    }
                    d.push_back(s[i] - '0');
                    i++;
                }
                if (!d.empty() && !flag)
                {
                    long double num = cal(d);
                    long double ans = (disc *num) / 100.0;
                    num -= ans;
                    string str = to_string(num);
                    num = round(num *100.0) / 100.0;
                    string num_text = to_string(num);
                    string temp = num_text.substr(0, num_text.find(".") + 3);
                   	// string temp;
                   	// int m = str.size();
                   	// int k = 0;
                   	// while (str[k] != '.')
                   	// {
                   	//     temp += str[k];
                   	//     k++;
                   	// }
                   	// temp += str[k];
                   	// temp += str[k + 1];
                   	// temp += str[k + 2];
                    res += temp;
                    if (i < n)
                        res += s[i];
                }
            }
            if (flag)
            {
               	// cout<<flag<<endl;
               	// cout<<j+1<<" "<<i<<endl;
                for (int k = j + 1; k <= i; k++)
                    res += s[k];
            }
            i++;
        }
        return res;
    }
};