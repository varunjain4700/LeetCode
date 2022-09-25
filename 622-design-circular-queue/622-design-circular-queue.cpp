class MyCircularQueue
{
    public:
        vector<int> queue;
    int cnt = 0, front = 0, rear = 0;
    int sz;
    MyCircularQueue(int k)
    {
        sz = k;
        queue.resize(k);
    }

    bool enQueue(int value)
    {
        if (cnt == sz)
            return false;
        queue[rear % sz] = value;
        rear++;
        cnt++;
        return true;
    }

    bool deQueue()
    {
        if (cnt == 0)
            return false;
        front++;
        cnt--;
        return true;
    }

    int Front()
    {
        if (cnt == 0)
            return -1;
        return queue[front % sz];
    }

    int Rear()
    {
        if (cnt == 0)
            return -1;
        return queue[(rear - 1) % sz];
    }

    bool isEmpty()
    {
        if (cnt == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (cnt == sz)
            return true;
        return false;
    }
};

/**
 *Your MyCircularQueue object will be instantiated and called as such:
 *MyCircularQueue* obj = new MyCircularQueue(k);
 *bool param_1 = obj->enQueue(value);
 *bool param_2 = obj->deQueue();
 *int param_3 = obj->Front();
 *int param_4 = obj->Rear();
 *bool param_5 = obj->isEmpty();
 *bool param_6 = obj->isFull();
 */