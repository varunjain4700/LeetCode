class NumArray
{
    public:
        int seg[100001] = { 0 };
    int n;
    void upd(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr && tl == pos)
        {
            seg[v] = val;
            return;
        }
        if (pos < tl || pos > tr)
            return;
        int tm = (tl + tr) / 2;
        upd(2 *v, tl, tm, pos, val);
        upd(2 *v + 1, tm + 1, tr, pos, val);
        seg[v] = seg[2 *v] + seg[2 *v + 1];
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > tr || r < tl)
            return 0;
        if (l <= tl && r >= tr)
            return seg[v];
        int tm = (tl + tr) / 2;
        return query(2 *v, tl, tm, l, r) + query(2 *v + 1, tm + 1, tr, l, r);
    }
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        for (int i = 0; i < n; i++)
            upd(1, 0, n - 1, i, nums[i]);
    }

    void update(int index, int val)
    {
        upd(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *obj->update(index,val);
 *int param_2 = obj->sumRange(left,right);
 */