class Solution
{
    public:
        void solve(vector<string> &res, string temp, int k)
        {
            if (k == 0)
            {
               	//cout<<temp<<" ";
                res.push_back(temp);
                return;
            }
             if (temp.empty())
            {
                temp += "a";
                solve(res, temp, k - 1);
                temp.pop_back();
                temp += "b";
                solve(res, temp, k - 1);
                temp.pop_back();
                temp += "c";
                solve(res, temp, k - 1);
            }
            else if (temp.back() == 'a')
            {
                temp += 'b';
                solve(res, temp, k - 1);
                temp.pop_back();
                temp += 'c';
                solve(res, temp, k - 1);
            }
            else if (temp.back() == 'b')
            {
                temp += "a";
                solve(res, temp, k - 1);
                temp.pop_back();
                temp += "c";
                solve(res, temp, k - 1);
            }
            else if (temp.back() == 'c')
            {
                temp += "a";
                solve(res, temp, k - 1);
                temp.pop_back();
                temp += "b";
                solve(res, temp, k - 1);
            }
        }
    string getHappyString(int n, int k)
    {
        vector<string> res;
        string temp = "";
        solve(res, temp, n);
        sort(res.begin(), res.end());
        if (res.size() < k)
            return "";
        return res[k - 1];
    }
};