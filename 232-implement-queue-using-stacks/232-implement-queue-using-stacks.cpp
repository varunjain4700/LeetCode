class MyQueue
{
    public:
        stack<int> st1, st2;
    MyQueue() {}

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        int num;
        if (!st2.empty())
        {
            num = st2.top();
            st2.pop();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            num = st2.top();
            st2.pop();
        }
        return num;
    }

    int peek()
    {
        int num;
        if (!st2.empty())
        {
            num = st2.top();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            num = st2.top();
        }
        return num;
    }

    bool empty()
    {
        if (!st2.empty() || !st1.empty())
            return false;
        return true;
    }
};

/**
 *Your MyQueue object will be instantiated and called as such:
 *MyQueue* obj = new MyQueue();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->peek();
 *bool param_4 = obj->empty();
 */