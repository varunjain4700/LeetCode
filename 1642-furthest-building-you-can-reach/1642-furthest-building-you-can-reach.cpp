class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            int n = heights.size();
            priority_queue<int, vector < int>, greater < int>> pq;
            int bricks_reqd = 0;
            for (int i = 1; i < n; i++)
            {
                if (heights[i] - heights[i - 1] <= 0)
                    continue;
                int dis = heights[i] - heights[i - 1];
                if (pq.size() < ladders)
                    pq.push(dis);
                else if (!pq.empty() && dis > pq.top())
                {
                    bricks_reqd += pq.top();
                    pq.pop();
                    pq.push(dis);
                }
                else
                {
                    bricks_reqd += dis;
                }
                if (bricks_reqd > bricks)
                    return i - 1;
            }
            return n - 1;
        }
};