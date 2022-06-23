class Solution
{
    public:
        int minRefuelStops(int target, int startFuel, vector<vector < int>> &stations)
        {
            int n = stations.size();
            if (n == 0 && startFuel < target)
                return -1;
            priority_queue<int> pq;
            int available = startFuel, reqd = 0, stops = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    reqd = min(target, stations[i][0]);
                }
                else
                    reqd = min(target, stations[i][0]) - stations[i - 1][0];
               	// cout<<reqd<<" "<<available<<endl;
                while (!pq.empty() && available < reqd)
                {
                    available += pq.top();
                    pq.pop();
                    stops++;
                }
                if (available >= reqd)
                    available -= reqd;
                else
                    return -1;
                if (target <= stations[i][0])
                    return stops;
                pq.push(stations[i][1]);
            }
            if (n > 0 && target > stations[n - 1][0])
            {
                reqd = target - stations[n - 1][0];
                while (!pq.empty() && available < reqd)
                {
                    available += pq.top();
                    pq.pop();
                    stops++;
                }
                if (available >= reqd)
                    available -= reqd;
                else
                    return -1;
            }
            return stops;
        }
};