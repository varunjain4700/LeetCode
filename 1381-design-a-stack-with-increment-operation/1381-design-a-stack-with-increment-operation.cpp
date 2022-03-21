class CustomStack
{
    public:
        stack<int> st;
    vector<int> inc;
    int max_size = 0;
    CustomStack(int maxSize)
    {
        max_size = maxSize;
    }

    void push(int x)
    {
        if (st.size() == max_size)
            return;
        st.push(x);
        inc.push_back(0);
    }

    int pop()
    {
        if (st.empty())
            return -1;
        int num = st.top();
        int extra = inc[st.size() - 1];
        if (st.size() > 1)
            inc[st.size() - 2] += inc[st.size() - 1];
        inc[st.size() - 1] = 0;
        st.pop();
        inc.pop_back();
        return num + extra;
    }

    void increment(int k, int val)
    {
       	//increment bottom k elements of stack by val
        if (st.size() < k && st.size() > 0)
            inc[st.size() - 1] += val;
        else if (st.size() >= k)
            inc[k - 1] += val;
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */