class MedianFinder
{
    public:
        priority_queue<int> maxm;
    priority_queue<int, vector < int>, greater < int>> minm;
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxm.empty())
            maxm.push(num);
        else if (maxm.size() == minm.size())
        {
            if (num <= minm.top())
                maxm.push(num);
            else
            {
                maxm.push(minm.top());
                minm.pop();
                minm.push(num);
            }
        }
        else
        {
            if (num > maxm.top())
                minm.push(num);
            else
            {
                minm.push(maxm.top());
                maxm.pop();
                maxm.push(num);
            }
        }
    }

    double findMedian()
    {
        double ans = 0;
        if (maxm.size() == minm.size())
            ans = (double)(maxm.top() + minm.top()) / 2;
        else
            ans = maxm.top();
        return ans;
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */