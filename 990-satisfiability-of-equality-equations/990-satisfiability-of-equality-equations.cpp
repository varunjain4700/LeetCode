class Solution
{
    public:
        vector<int> par, sz;
    void init()
    {
        for (int i = 0; i < 26; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == par[x])
            return x;
        return x = find(par[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (sz[y] > sz[x])
            swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool equationsPossible(vector<string> &nums)
    {
        par.resize(26, 0);
        sz.resize(26, 0);
        init();
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int a = nums[i][0] - 'a';
            int b = nums[i][3] - 'a';
            char sign = nums[i][1];
            if (sign == '=')
            {
                if (find(a) != find(b))
                    merge(a, b);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int a = nums[i][0] - 'a';
            int b = nums[i][3] - 'a';
            char sign = nums[i][1];
            if (sign == '!')
            {
                if (find(a) == find(b))
                    return false;
            }
        }
        return true;
    }
};