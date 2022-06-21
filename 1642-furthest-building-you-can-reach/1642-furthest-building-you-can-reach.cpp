class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            int n = heights.size();
            priority_queue<int, vector < int>, greater < int>> pq;
           	//keeping the max differences in min.priority queue and will select a ladder to cover them.rest of them will be covered using bricks
            int i = 1, sum = 0;
            while (i < n)
            {
                if (heights[i] - heights[i - 1] <= 0)
                {
                    i++;
                    continue;
                }
                int diff = heights[i] - heights[i - 1];
                if (pq.size() <= ladders)
                {
                    pq.push(diff);
                }
                if (!pq.empty() && pq.size() > ladders)
                {
                    sum += pq.top();
                    pq.pop();
                }
               	//cout<<i<<"-"<<sum<<endl;
                if (sum > bricks)
                    return i - 1;
                i++;
            }
            return i - 1;
        }
};