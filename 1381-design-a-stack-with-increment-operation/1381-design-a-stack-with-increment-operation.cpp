class CustomStack
{
    public:
        stack<int> st;
    int inc[1001] = { 0 };
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
    }

    int pop()
    {
        if (st.empty())
            return -1;
        int num = st.top();
        int extra = inc[st.size()];
        inc[st.size() - 1] += inc[st.size()];
        inc[st.size()] = 0;
        st.pop();
        return num + extra;
    }

    void increment(int k, int val)
    {
       	//increment bottom k elements of stack by val
        if (st.size() < k)
            inc[st.size()] += val;
        else
            inc[k] += val;
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */