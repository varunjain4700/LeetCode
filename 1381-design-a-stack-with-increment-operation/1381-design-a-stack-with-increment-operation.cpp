class CustomStack
{
    public:
        stack<int> st;
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
        st.pop();
        return num;
    }

    void increment(int k, int val)
    {
       	//increment bottom k elements of stack by val
        vector<int> temp;
        while (!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        int idx = temp.size() - 1;
        while (k > 0 && idx >= 0)
        {
            temp[idx] += val;
            k--;
            idx--;
        }
        int n = temp.size() - 1;
        for (int i = n; i >= 0; i--)
            st.push(temp[i]);
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */