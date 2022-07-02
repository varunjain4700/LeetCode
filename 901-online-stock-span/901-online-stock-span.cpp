class StockSpanner
{
    public:
       	//need to find nearest greater to left for each element
        stack<pair<int, int>> st;
    int cnt = 0;
    StockSpanner() {}

    int next(int price)
    {
        cnt++;
        int ngl = 0;	//storing idx of ngl element
        if (st.empty())
            ngl = 0;
        else if (st.top().first > price)
            ngl = st.top().second;
        else
        {
            while (!st.empty() && st.top().first <= price)
                st.pop();
            if (st.empty())
                ngl = 0;
            else
                ngl = st.top().second;
        }
        st.push({ price,
            cnt });
        return cnt - ngl;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */