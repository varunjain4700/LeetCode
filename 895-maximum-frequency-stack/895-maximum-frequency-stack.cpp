class FreqStack
{
    public:
    priority_queue<pair<pair<int, int>, int>> pq;
    unordered_map<int, int> freq;
    int t = 0;
    FreqStack() {}

    void push(int val)
    {
        t++;
        freq[val]++;
        pq.push({{ freq[val], t},val });
    }

    int pop()
    {
        t++;
        pair<pair<int, int>, int> p = pq.top();
        pq.pop();
        int num = p.second;
        freq[num]--;
        return num;
    }
};

/**
 *Your FreqStack object will be instantiated and called as such:
 *FreqStack* obj = new FreqStack();
 *obj->push(val);
 *int param_2 = obj->pop();
 */